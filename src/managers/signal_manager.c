#include "o1/managers/signal_manager.h"

#include <assert.h>

/*****************************************************************************/
/*                                    API                                    */
/*****************************************************************************/

struct signal*
signal_manager_emit_signal(struct signal_manager* manager,
                           const char* signal_name)
{
  assert(manager);
  assert(signal_name);

  static struct signal null_signal;

  return &null_signal;
}
