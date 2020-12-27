#include "device.h"
#include <cassert>
#include <cstdio>

NS_UGI_GRAPHICS_BEGIN

namespace dx11 {

    bool Device::initialize() {
        #ifndef NDEBUG
            uint32_t createDeviceFlags = D3D11_CREATE_DEVICE_DEBUG;
    #else
            uint32_t createDeviceFlags = 0;
    #endif
            D3D_DRIVER_TYPE driverType[] = {
                D3D_DRIVER_TYPE_HARDWARE,
                D3D_DRIVER_TYPE_WARP,
                D3D_DRIVER_TYPE_REFERENCE,
            };
            const uint32_t numDriverTypes = sizeof(driverType)/sizeof(driverType[0]);
            D3D_FEATURE_LEVEL featureLevels[] = {
                D3D_FEATURE_LEVEL_11_1,
                D3D_FEATURE_LEVEL_11_0,
            };
            const uint32_t numFeatureLevels = sizeof(featureLevels)/sizeof(featureLevels[0]);
            // select a valide feature level & driver type
            D3D_DRIVER_TYPE selectDriverType;
            D3D_FEATURE_LEVEL selectFeatureLevel;
            HRESULT hr;

            ID3D11Device* device = nullptr;
            ID3D11DeviceContext* context = nullptr;
            for( uint32_t driverTypeIndex = 0; driverTypeIndex<numDriverTypes; ++driverTypeIndex ) {
                selectDriverType = driverType[driverTypeIndex];
                hr = D3D11CreateDevice(
                    nullptr, selectDriverType, nullptr, createDeviceFlags, &featureLevels[0], numFeatureLevels, 
                    D3D11_SDK_VERSION,
                    &device, &selectFeatureLevel, &context
                );
                // 如果返回值是887a002d, 在控制面板里应用和功能里添加可用功能（图形工具）
                if( hr == E_INVALIDARG) { // 不支持11.1, 创建11.0
                    hr = D3D11CreateDevice(
                        nullptr, selectDriverType, nullptr, createDeviceFlags, &featureLevels[1], 1,
                        D3D11_SDK_VERSION, 
                        &device, &selectFeatureLevel, &context
                    );
                    if(SUCCEEDED(hr)) {
                        _minorVersion = 0;
                        break;
                    }
                } else {
                    if(SUCCEEDED(hr)) {
                        _minorVersion = 1;
                        break;
                    }
                }
            }
            if(FAILED(hr)) {
                printf("Create D3D11 Device Failed!");
                return false;
            }
            // 确认支持的特性(实际根本没必要的，这代码是我抄来的，估计写这段代码的小哥没意识到)
            if ( selectFeatureLevel != D3D_FEATURE_LEVEL_11_0 && selectFeatureLevel != D3D_FEATURE_LEVEL_11_1) {
                printf("Direct3D Feature Level 11 unsupported.");
                return false;
            }
            device->CheckMultisampleQualityLevels( DXGI_FORMAT_R8G8B8A8_UNORM, 4, &_msaaQuality );
            assert( _msaaQuality && "这个是一定会支持的！");
            //
            _device = device;
            _context = context;
            //
            return true;
    }

}
NS_UGI_GRAPHICS_END