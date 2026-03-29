#ifndef ENGINE_H
#define ENGINE_H

#include "o1/frontend/display.h"
#include "o1/managers/display_manager.h"
#include "o1/managers/signal_manager.h"
#include "o1/managers/time_manager.h"

#include <assert.h>

/*****************************************************************************/
/*                                   TYPES                                   */
/*****************************************************************************/

struct engine
{
  struct display_manager display_manager;
  struct signal_manager signal_manager;
  struct time_manager time_manager;
};

#define ENGINE_INITIALIZER                                                     \
  ((struct engine){                                                            \
    .display_manager = DISPLAY_MANAGER_INITIALIZER,                            \
    .signal_manager = SIGNAL_MANAGER_INITIALIZER,                              \
    .time_manager = TIME_MANAGER_INITIALIZER,                                  \
  })

/*****************************************************************************/
/*                                 LIFE CYCLE                                */
/*****************************************************************************/

void
engine_initialize_foundation(struct engine* engine, int argc, char* argv[]);
void
engine_initialize_kernel(struct engine* engine);
void
engine_initialize_scripts(struct engine* engine);
void
engine_initialize_runtime(struct engine* engine);
void
engine_initialize_frontend(struct engine* engine);

void
engine_finalize_foundation(struct engine* engine);
void
engine_finalize_kernel(struct engine* engine);
void
engine_finalize_scripts(struct engine* engine);
void
engine_finalize_runtime(struct engine* engine);
void
engine_finalize_frontend(struct engine* engine);

/*****************************************************************************/
/*                                   FRAMES                                  */
/*****************************************************************************/

[[nodiscard]] bool
engine_is_running(const struct engine* engine);
[[nodiscard]] bool
engine_has_errors(const struct engine* engine);
[[nodiscard]] bool
engine_has_no_errors(const struct engine* engine);

void
engine_begin_frame(struct engine* engine);
void
engine_end_frame(struct engine* engine);

void
engine_process_events(struct engine* engine);
void
engine_process_signals(struct engine* engine);
void
engine_process_commands(struct engine* engine);

void
engine_update_kernel(struct engine* engine, double delta);
void
engine_update_scripts(struct engine* engine, double delta);
void
engine_update_runtime(struct engine* engine, double delta);

void
engine_fixed_update_kernel(struct engine* engine, double delta);
void
engine_fixed_update_scripts(struct engine* engine, double delta);
void
engine_fixed_update_runtime(struct engine* engine, double delta);

void
engine_render_kernel(struct engine* engine,
                     struct display* display,
                     double delta);
void
engine_render_scripts(struct engine* engine,
                      struct display* display,
                      double delta);
void
engine_render_runtime(struct engine* engine,
                      struct display* display,
                      double delta);

/*****************************************************************************/
/*                                 ACCESSORS                                 */
/*****************************************************************************/

[[nodiscard]] static inline struct display_manager*
engine_display_manager(struct engine* engine)
{
  assert(engine);
  return &engine->display_manager;
}

[[nodiscard]] static inline struct signal_manager*
engine_signal_manager(struct engine* engine)
{
  assert(engine);
  return &engine->signal_manager;
}

[[nodiscard]] static inline struct time_manager*
engine_time_manager(struct engine* engine)
{
  assert(engine);
  return &engine->time_manager;
}

#endif /* ENGINE_H */
