#ifndef MEMORY_H
#define MEMORY_H

#include <stdalign.h>
#include <stddef.h>

/*****************************************************************************/
/*                                   TYPES                                   */
/*****************************************************************************/

typedef void* (*memory_allocate_function)(void* user,
                                          size_t num_bytes,
                                          size_t align);
typedef void (*memory_deallocate_function)(void* user,
                                           void* ptr,
                                           size_t num_bytes,
                                           size_t align);
typedef void* (*memory_reallocate_function)(void* user,
                                            void* ptr,
                                            size_t old_num_bytes,
                                            size_t new_num_bytes,
                                            size_t old_align,
                                            size_t new_align);

struct memory_allocator
{
  void* user;
  memory_allocate_function alloc_func;
  memory_deallocate_function dealloc_func;
  memory_reallocate_function realloc_func;
};

/*****************************************************************************/
/*                                    API                                    */
/*****************************************************************************/

#define MEMORY_ALLOCATE(Mem, T)                                                \
  ((T*)memory_allocate(Mem, sizeof(T), alignof(T)))
#define MEMORY_ALLOCATE_ARRAY(Mem, T, Count)                                   \
  ((T*)memory_allocate(Mem, (Count) * sizeof(T), alignof(T)))

[[nodiscard]] static inline void*
memory_allocate(struct memory_allocator* mem, size_t num_bytes, size_t align)
{
  if (!mem)
    return nullptr;
  if (!mem->alloc_func)
    return nullptr;
  return mem->alloc_func(mem->user, num_bytes, align);
}

#define MEMORY_DEALLOCATE(Mem, Ptr)                                            \
  memory_deallocate(Mem, Ptr, sizeof(*(Ptr)), alignof(typeof(*(Ptr))))
#define MEMORY_DEALLOCATE_ARRAY(Mem, Ptr, Count)                               \
  memory_deallocate(Mem, Ptr, (Count) * sizeof(*(Ptr)), alignof(typeof(*(Ptr))))

static inline void*
memory_deallocate(struct memory_allocator* mem,
                  void* ptr,
                  size_t num_bytes,
                  size_t align)
{
  if (!mem)
    return ptr;
  if (!mem->dealloc_func)
    return ptr;

  mem->dealloc_func(mem->user, ptr, num_bytes, align);
  return nullptr;
}

#define MEMORY_REALLOCATE(Mem, Ptr)                                            \
  ((typeof(Ptr))memory_reallocate(Mem,                                         \
                                  Ptr,                                         \
                                  sizeof(*(Ptr)),                              \
                                  sizeof(*(Ptr)),                              \
                                  alignof(typeof(*(Ptr))),                     \
                                  alignof(typeof(*(Ptr)))))
#define MEMORY_REALLOCATE_ARRAY(Mem, Ptr, OldCount, NewCount)                  \
  ((typeof(Ptr))memory_reallocate(Mem,                                         \
                                  Ptr,                                         \
                                  (OldCount) * sizeof(*(Ptr)),                 \
                                  (NewCount) * sizeof(*(Ptr)),                 \
                                  alignof(typeof(*(Ptr))),                     \
                                  alignof(typeof(*(Ptr)))))

[[nodiscard]] static inline void*
memory_reallocate(struct memory_allocator* mem,
                  void* ptr,
                  size_t old_num_bytes,
                  size_t new_num_bytes,
                  size_t old_align,
                  size_t new_align)
{
  if (!mem)
    return nullptr;
  if (!mem->realloc_func)
    return nullptr;
  return mem->realloc_func(
    mem->user, ptr, old_num_bytes, new_num_bytes, old_align, new_align);
}

/*****************************************************************************/
/*                                  HELPERS                                  */
/*****************************************************************************/

[[nodiscard]] static inline bool
memory_align_is_power_of_two(size_t align)
{
  if (align == 0)
    return false;
  return (((align) & (align - 1)) == 0);
}

#endif /* MEMORY_H */
