#include "swapchain.h"

NS_UGI_GRAPHICS_BEGIN

namespace dx11 {

        bool Swapchain::ready() const {
            return !!_swapchain;
        }

        void Swapchain::clear( float(& channels)[4], float depth, uint32_t stencil ) {

        }

        void Swapchain::present() {

        }

        bool Swapchain::onResize( uint32_t width, uint32_t height ) {
            
        }

}

NS_UGI_GRAPHICS_END