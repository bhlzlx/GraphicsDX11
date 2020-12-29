#include "graphics_dx11_decl.h"
#include <graphics_type.h>
#include <graphics.h>

NS_UGI_GRAPHICS_DX11_BEGIN

class Texture: public ITexture  {
private:
    ID3D11Texture2D*        _texture;
    TextureDescription      _desc;
    //
public:

    Texture( ID3D11Texture2D* texture );
    //Texture( ID3D11Texture3D* texture );

    virtual const TextureDescription& desc() const override {
        return _desc;
    }
    
};

NS_UGI_GRAPHICS_DX11_END