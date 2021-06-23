project('comet', 'cpp', version: '0.1.0')

comet_header_files = files(
    'include/comet/hello.hpp',
    'include/comet/base/types.hpp',
    'include/comet/graphics/window.hpp',
    'include/comet/exceptions/exception.hpp',
)

comet_source_files = files(
    'source/comet/hello.cpp',
    'source/comet/graphics/window.cpp',
    'source/comet/exceptions/exception.cpp',
)

comet_dependencies = [
    dependency('glfw3')
]

comet_library = library(
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
