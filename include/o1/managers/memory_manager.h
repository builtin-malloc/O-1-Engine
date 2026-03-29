#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include "o1/memory.h"

/*****************************************************************************/
/*                                   TYPES                                   */
/*****************************************************************************/

struct memory_manager
{
  struct memory_allocator heap_allocator;
  struct memory_allocator frame_scratch_allocator;
};

#define MEMORY_MANAGER_INITIALIZER                                             \
  ((struct memory_manager){                                                    \
    .heap_allocator = { 0 },                                                   \
    .frame_scratch_allocator = { 0 },                                          \
  })

#endif /* MEMORY_MANAGER_H */
