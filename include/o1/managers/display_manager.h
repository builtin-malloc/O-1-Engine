#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include "o1/frontend/display.h"

#include <assert.h>

/*****************************************************************************/
/*                                   TYPES                                   */
/*****************************************************************************/

struct display_manager
{
  struct display* displays_begin;
  struct display* displays_end;
};

#define DISPLAY_MANAGER_INITIALIZER                                            \
  ((struct display_manager){                                                   \
    .displays_begin = nullptr,                                                 \
    .displays_end = nullptr,                                                   \
  })

/*****************************************************************************/
/*                                 LIFE CYCLE                                */
/*****************************************************************************/

void
display_manager_initialize(struct display_manager* manager);
void
display_manager_finalize(struct display_manager* manager);

/*****************************************************************************/
/*                                    API                                    */
/*****************************************************************************/

void
display_manager_create_main_display(struct display_manager* manager);

/*****************************************************************************/
/*                                 ITERATION                                 */
/*****************************************************************************/

[[nodiscard]] static inline struct display*
display_manager_begin(struct display_manager* manager)
{
  assert(manager);
  return manager->displays_begin;
}

[[nodiscard]] static inline struct display*
display_manager_end(struct display_manager* manager)
{
  assert(manager);
  return manager->displays_end;
}

#endif /* DISPLAY_MANAGER_H */
