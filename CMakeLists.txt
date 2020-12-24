project( graphics )

set( CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/3rd/generalCMakeModule )

include( basicEnv )
include( outputPath )

add_subdirectory( src/libgraphics )