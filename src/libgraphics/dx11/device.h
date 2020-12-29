#include <graphics.h>

#include "graphics_dx11_decl.h"

// d3d 11 headers
#include <dxgi.h>
#include <d3dcommon.h>
#include <d3d11.h>
#include <d3d11_1.h>
#include <wrl/client.h>

NS_UGI_GRAPHICS_BEGIN

namespace dx11 {
    class Device : IDevice {
    private:
        ID3D11Device*               _device;
        ID3D11DeviceContext*        _context;
        size_t                      _videoMemorySize;
        uint32_t                    _minorVersion;
        uint32_t                    _msaaQuality;
        char                        _videoCardDesc[128];
        uint32_t                    _swapchainBufferCount;
    private:
        bool initialize();
        uint32_t minorVersion() const { return _minorVersion; }
    public:
        virtual ITexture* createTexture( const ugi::TextureDescription& desc ) const override ;
        // virtual ITexture* createTexture( const )
        virtual IRenderPass* createRenderPass( const ugi::RenderPassDescription& desc, ITexture** textures, ITexture* depthStencil ) const override;
        virtual IGraphicsPipeline* createGraphcisPipeline( const ugi::PipelineDescription& desc ) const override;
    };

    IDevice* createDeviceDX11();
}

NS_UGI_GRAPHICS_END