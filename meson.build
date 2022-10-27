project('X-Plane Plugin Template', 'cpp',
    default_options : [
      'cpp_std=c++17'
])

add_project_arguments('-DXPLM200', '-DXPLM210', '-DXPLM300', '-DXPLM301', language: 'cpp')

if host_machine.system() == 'darwin'
    add_project_arguments('-DAPL=1', language: 'cpp')
elif host_machine.system() == 'windows'
    add_project_arguments('-DIBM=1', language: 'cpp')
elif host_machine.system() == 'linux'
    add_project_arguments('-DLIN=1', language: 'cpp')
endif

xpsdk_dep = dependency('appleframeworks', modules: 'XPLM')
xpsdk_inc = include_directories('SDK/CHeaders/XPLM')

subdir('src')
