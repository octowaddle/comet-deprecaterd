project('comet', 'cpp', default_options: ['cpp_std=c++17'], version: '0.1.0')

compiler = meson.get_compiler('cpp')

comet_header_files = files(
    'include/comet/hello.hpp',
    'include/comet/base/types.hpp',
    'include/comet/graphics/window.hpp',
    'include/comet/exceptions/exception.hpp',
    'include/comet/events/event.hpp',
    'include/comet/events/event_queue.hpp',
    'include/comet/events/key_events/key_event.hpp',
    'include/comet/events/window_events/window_event.hpp',
    'include/comet/events/window_events/window_close_event.hpp',
    'include/comet/events/window_events/window_resize_event.hpp',
)

comet_source_files = files(
    'source/comet/hello.cpp',
    'source/comet/graphics/window.cpp',
    'source/comet/exceptions/exception.cpp',
    'source/comet/events/event.cpp',
    'source/comet/events/event_queue.cpp',
    'source/comet/events/key_events/key_event.cpp',
    'source/comet/events/window_events/window_event.cpp',
    'source/comet/events/window_events/window_resize_event.cpp',
)

glfw3_dependency = dependency('glfw3', required: false)
if not glfw3_dependency.found()
    glfw3_dependency = compiler.find_library('glfw3', required: false)
endif

comet_dependencies = [
    glfw3_dependency
]

comet_library = static_library(
    'comet',
    [comet_header_files, comet_source_files],
    dependencies: comet_dependencies,
    include_directories: 'include',
    install: true,
)

comet_dependency = declare_dependency(
    include_directories: 'include',
    link_with: comet_library,
)

subdir('tests/sandbox')
