#!/bin/bash

# This script regenerates subprojects/packagefiles/sdk_patch.tar.gz in case
# it needs modifications.

set -x

mkdir SDK
cat > SDK/meson.build <<__MESONBUILD
project('X-Plane SDK', 'c')

cc = meson.get_compiler('c')

if host_machine.system() == 'darwin'
    sdk_dep = declare_dependency(
        link_args: ['-framework', 'XPLM', '-F', meson.current_source_dir() + '/Libraries/Mac'],
        include_directories: include_directories(['CHeaders/XPLM'])
    )
endif

if host_machine.system() == 'windows'
    sdk_dep = declare_dependency(
        link_args: ['-LXPLM_64', '-L', meson.current_source_dir() + '/Libraries/Win'],
        include_directories: include_directories(['CHeaders/XPLM'])
    )
endif

if host_machine.system() == 'linux'
    sdk_dep = declare_dependency(
        include_directories: include_directories(['CHeaders/XPLM']),
        link_args: ['-shared', '-rdynamic', '-nodefaultlibs', '-undefined_warning']
    )
endif
__MESONBUILD

tar -czf subprojects/packagefiles/sdk_patch.tar.gz SDK
rm -rf SDK
