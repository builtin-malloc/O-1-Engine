#include "o1/engine.h"
#include "o1/managers/display_manager.h"
#include "o1/managers/signal_manager.h"
#include "o1/managers/time_manager.h"

#include <stdlib.h>

int
main(int argc, char* argv[])
{
  static struct engine engine = ENGINE_INITIALIZER;

  auto time = engine_time_manager(&engine);
  auto displays = engine_display_manager(&engine);
  auto signals = engine_signal_manager(&engine);

  engine_initialize_foundation(&engine, argc, argv);
  engine_initialize_kernel(&engine);
  engine_initialize_scripts(&engine);
  engine_initialize_runtime(&engine);
  engine_initialize_frontend(&engine);

  display_manager_create_main_display(displays);
  signal_manager_emit_signal(signals, "o1::start");

  while (engine_is_running(&engine) && engine_has_no_errors(&engine)) {
    engine_process_events(&engine);
    engine_process_signals(&engine);
    engine_process_commands(&engine);

    engine_begin_frame(&engine);

    auto delta = time_manager_delta(time);
    auto fixed_delta = time_manager_fixed_delta(time);

    engine_update_kernel(&engine, delta);
    engine_update_scripts(&engine, delta);
    engine_update_runtime(&engine, delta);

    while (time_manager_should_run_fixed_updates(time)) {
      engine_fixed_update_kernel(&engine, fixed_delta);
      engine_fixed_update_scripts(&engine, fixed_delta);
      engine_fixed_update_runtime(&engine, fixed_delta);
    }

    for (auto cur = display_manager_begin(displays),
              end = display_manager_end(displays);
         cur != end;
         ++cur) {
      display_begin_frame(cur);
      engine_render_kernel(&engine, cur, delta);
      engine_render_scripts(&engine, cur, delta);
      engine_render_runtime(&engine, cur, delta);
      display_end_frame(cur);
    }

    engine_end_frame(&engine);
  }

  signal_manager_emit_signal(signals, "o1::stop");
  engine_process_signals(&engine);
  engine_process_commands(&engine);

  engine_finalize_frontend(&engine);
  engine_finalize_runtime(&engine);
  engine_finalize_scripts(&engine);
  engine_finalize_kernel(&engine);
  engine_finalize_foundation(&engine);

  return engine_has_no_errors(&engine) ? EXIT_SUCCESS : EXIT_FAILURE;
}
