#pragma once

#include <graphics_type.h>
#include "graphics_dx11_decl.h"

NS_UGI_GRAPHICS_BEGIN

namespace dx11 {

    class Swapchain {
    private:
        Device*                     _device;
        void*                       _hwnd;
        union {
            IDXGISwapChain*         _swapchain;
            IDXGISwapChain1*        _swapchain1;
        };
        ID3D11Texture2D*            _renderBuffers[MaxFlightCount];
        ID3D11Texture2D*            _depthStencilBuffer;
        ID3D11RenderTargetView*     _renderTargetViews[MaxFlightCount];
        ID3D11DepthStencilView*     _depthStencilView;
    public:
        Swapchain( Device* device, void* hwnd )
            : _device(device)
            , _hwnd(hwnd)
            , _swapchain( nullptr )
            , _renderBuffers {}
            , _depthStencilBuffer( nullptr )
            , _renderTargetViews {}
            , _depthStencilView(nullptr)
        {
        }

        bool ready() const;

        void clear( float(& channels)[4], float depth, uint32_t stencil );

        void present();

        bool onResize( uint32_t width, uint32_t height );
    };

}

NS_UGI_GRAPHICS_END