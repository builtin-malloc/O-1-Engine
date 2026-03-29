#ifndef SIGNAL_MANAGER_H
#define SIGNAL_MANAGER_H

#include "o1/signals/signal.h"

/*****************************************************************************/
/*                                   TYPES                                   */
/*****************************************************************************/

struct signal_manager
{
  int dummy;
};

#define SIGNAL_MANAGER_INITIALIZER ((struct signal_manager){ 0 })

/*****************************************************************************/
/*                                    API                                    */
/*****************************************************************************/

struct signal*
signal_manager_emit_signal(struct signal_manager* manager,
                           const char* signal_name);

#endif /* SIGNAL_MANAGER_H */
