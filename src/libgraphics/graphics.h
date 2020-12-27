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
    virtual IRenderPass* createTexture( const ugi::RenderPassDescription& desc, ITexture** textures, ITexture* depthStencil ) const;
    virtual IGraphicsPipeline* createGraphcisPipeline( const ugi::PipelineDescription& desc ) const;
    // swapchain 接口不必要添加，因为这东西可以封装到一个 renderpass 内
};

IDevice* createDevice( GraphicsApiType apiType );


NS_UGI_GRAPHICS_END