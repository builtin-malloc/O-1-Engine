#include "o1/managers/display_manager.h"

#include <GLAD/gl.h>
#include <GLFW/glfw3.h>

#include <stdio.h>

/*****************************************************************************/
/*                                 CALLBACKS                                 */
/*****************************************************************************/

static void
on_glfw_error(int code, const char* msg)
{
  // TODO: Use logging and error reporting
  fprintf(stderr, "[FATAL] GLFW Error #%d: %s\n", code, msg);
}

/*****************************************************************************/
/*                                 LIFE CYCLE                                */
/*****************************************************************************/

void
display_manager_initialize(struct display_manager* manager)
{
  assert(manager);

  glfwSetErrorCallback(on_glfw_error);
  glfwInit();
}

void
display_manager_finalize(struct display_manager* manager)
{
  assert(manager);

  glfwTerminate();
}

/*****************************************************************************/
/*                                    API                                    */
/*****************************************************************************/

void
display_manager_create_main_display(struct display_manager* manager)
{
  assert(manager);
}
