#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include <assert.h>

/*****************************************************************************/
/*                                   TYPES                                   */
/*****************************************************************************/

struct time_manager
{
  double delta;
  double fixed_delta;
  double accumulator;
};

#define TIME_MANAGER_INITIALIZER                                               \
  ((struct time_manager){                                                      \
    .delta = 1.0 / 60.0,                                                       \
    .fixed_delta = 1.0 / 60.0,                                                 \
    .accumulator = 0.0,                                                        \
  })

/*****************************************************************************/
/*                                  QUERIES                                  */
/*****************************************************************************/

[[nodiscard]] static inline double
time_manager_delta(const struct time_manager* manager)
{
  assert(manager);
  return manager->delta;
}

[[nodiscard]] static inline double
time_manager_fixed_delta(const struct time_manager* manager)
{
  assert(manager);
  return manager->fixed_delta;
}

[[nodiscard]] static inline double
time_manager_should_run_fixed_updates(const struct time_manager* manager)
{
  assert(manager);
  return manager->accumulator >= manager->fixed_delta;
}

#endif /* TIME_MANAGER_H */
