# graphics layer - implement by DX11
project( graphics )

add_library( graphics_dx11 STATIC )

target_sources( graphics_dx11 
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/dx11/device.cpp
    #PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/dx11/swapchain.cpp
    #PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/dx11/texture.cpp
    #PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/dx11/renderTarget.cpp
)