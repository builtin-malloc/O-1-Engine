#include "o1/engine.h"
#include "o1/managers/display_manager.h"

#include <assert.h>

/*****************************************************************************/
/*                                 LIFE CYCLE                                */
/*****************************************************************************/

void
engine_initialize_foundation(struct engine* engine,
                             [[maybe_unused]] int argc,
                             [[maybe_unused]] char* argv[])
{
  assert(engine);
}

void
engine_initialize_kernel(struct engine* engine)
{
  assert(engine);
}

void
engine_initialize_scripts(struct engine* engine)
{
  assert(engine);
}

void
engine_initialize_runtime(struct engine* engine)
{
  assert(engine);
}

void
engine_initialize_frontend(struct engine* engine)
{
  assert(engine);

  display_manager_initialize(&engine->display_manager);
}

void
engine_finalize_foundation(struct engine* engine)
{
  assert(engine);
}

void
engine_finalize_kernel(struct engine* engine)
{
  assert(engine);
}

void
engine_finalize_scripts(struct engine* engine)
{
  assert(engine);
}

void
engine_finalize_runtime(struct engine* engine)
{
  assert(engine);
}

void
engine_finalize_frontend(struct engine* engine)
{
  assert(engine);

  display_manager_finalize(&engine->display_manager);
}

/*****************************************************************************/
/*                                   FRAMES                                  */
/*****************************************************************************/

[[nodiscard]] bool
engine_is_running(const struct engine* engine)
{
  assert(engine);
  return false;
}

[[nodiscard]] bool
engine_has_errors(const struct engine* engine)
{
  assert(engine);
  return false;
}

[[nodiscard]] bool
engine_has_no_errors(const struct engine* engine)
{
  return !engine_has_errors(engine);
}

void
engine_begin_frame(struct engine* engine)
{
  assert(engine);
}

void
engine_end_frame(struct engine* engine)
{
  assert(engine);
}

void
engine_process_events(struct engine* engine)
{
  assert(engine);
}

void
engine_process_signals(struct engine* engine)
{
  assert(engine);
}

void
engine_process_commands(struct engine* engine)
{
  assert(engine);
}

void
engine_update_kernel(struct engine* engine, double delta)
{
  assert(engine);
  assert(delta >= 0);
}

void
engine_update_scripts(struct engine* engine, double delta)
{
  assert(engine);
  assert(delta >= 0);
}

void
engine_update_runtime(struct engine* engine, double delta)
{
  assert(engine);
  assert(delta >= 0);
}

void
engine_fixed_update_kernel(struct engine* engine, double delta)
{
  assert(engine);
  assert(delta >= 0);
}

void
engine_fixed_update_scripts(struct engine* engine, double delta)
{
  assert(engine);
  assert(delta >= 0);
}

void
engine_fixed_update_runtime(struct engine* engine, double delta)
{
  assert(engine);
  assert(delta);
}

void
engine_render_kernel(struct engine* engine,
                     struct display* display,
                     double delta)
{
  assert(engine);
  assert(display);
  assert(delta >= 0);
}

void
engine_render_scripts(struct engine* engine,
                      struct display* display,
                      double delta)
{
  assert(engine);
  assert(display);
  assert(delta >= 0);
}

void
engine_render_runtime(struct engine* engine,
                      struct display* display,
                      double delta)
{
  assert(engine);
  assert(display);
  assert(delta >= 0);
}
