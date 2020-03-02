#include <hdPbr/renderDelegate.h>
#include <hdPbr/rendererPlugin.h>

#include <pxr/imaging/hd/rendererPluginRegistry.h>

PXR_NAMESPACE_USING_DIRECTIVE

TF_REGISTRY_FUNCTION( TfType )
{
    HdRendererPluginRegistry::Define< pbr::HdPbrRendererPlugin >();
}

namespace pbr
{

HdRenderDelegate* HdPbrRendererPlugin::CreateRenderDelegate()
{
    return new HdPbrRenderDelegate();
}

void HdPbrRendererPlugin::DeleteRenderDelegate( HdRenderDelegate* renderDelegate )
{
    delete renderDelegate;
}

bool HdPbrRendererPlugin::IsSupported() const
{
    return true;
}

} // namespace pbr