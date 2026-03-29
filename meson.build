## =============================================================================
## == SETUP ====================================================================
## =============================================================================

project(
  'O1',
  'c',
  meson_version : '>= 1.3.0',
  version : '0.1.0',
  default_options : ['c_std=c23',
                     'warning_level=3',
		     'buildtype=debug'],
)

## =============================================================================
## == DEPENDENCIES =============================================================
## =============================================================================

glad = static_library('glad', 'lib/GLAD/src/gl.c', include_directories : 'lib/GLAD/include',)
glad_dep = declare_dependency(link_with : [ glad ], include_directories : 'lib/GLAD/include',)

glfw_dep = dependency('glfw3')

## =============================================================================
## == LIBRARY ==================================================================
## =============================================================================

lib_src = [
  'src/engine.c',

  'src/managers/display_manager.c',
  'src/managers/signal_manager.c',

  'src/frontend/display.c',
]

lib = static_library(
  'O1',
  lib_src,
  include_directories : 'include',
  dependencies : [ glad_dep, glfw_dep ],
  install : true,
)

lib_dep = declare_dependency(
  link_with : [ lib ],
  include_directories : 'include',
)

## =============================================================================
## == BINARY ===================================================================
## =============================================================================

exe_src = [
  'app/main.c',
]

exe = executable(
  'O1',
  exe_src,
  dependencies : [ lib_dep, glad_dep, glfw_dep ],
  install : true,
)

