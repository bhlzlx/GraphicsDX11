#pragma once

#include "graphics_decl.h"
#include "graphics_type.h"

NS_UGI_GRAPHICS_BEGIN

enum class GraphicsApiType {
    dx11 = 0,
    dx12,
    vulkan,
    opengl_core_4_5,
    opengl_es_3_2,
};

class IDevice {
public:
    virtual ITexture* createTexture( const ugi::TextureDescription& desc ) const;
    virtual IRenderPass* createTexture( const ugi::RenderPassDescription& desc, ITexture** textures, ITexture* depthStencil );
    virtual ISwapchain* 
};



IDevice* createDevice( GraphicsApiType apiType );


NS_UGI_GRAPHICS_END