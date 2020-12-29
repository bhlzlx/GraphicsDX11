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
    virtual ITexture* createTexture( const ugi::TextureDescription& desc ) const = 0;
    virtual IRenderPass* createRenderPass( const ugi::RenderPassDescription& desc, ITexture** textures, ITexture* depthStencil ) const = 0;
    virtual IGraphicsPipeline* createGraphcisPipeline( const ugi::PipelineDescription& desc ) const = 0;
    // swapchain 接口不必要添加，因为这东西可以封装到一个 renderpass 内
    virtual ~IDevice() {}
};

class ITexture {
public:
    virtual const TextureDescription& desc() const = 0;
    virtual ~ITexture() {}
};

class ITextureView {
public:
    virtual ~ITextureView() {}
};

class IRenderTargetView {
public:
    virtual ~IRenderTargetView() {}
};

class IDepthStencilView {
public:
    virtual ~IDepthStencilView() {}
};

IDevice* createDevice( GraphicsApiType apiType );


NS_UGI_GRAPHICS_END