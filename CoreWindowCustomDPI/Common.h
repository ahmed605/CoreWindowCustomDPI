#pragma once

#include <Windows.h>
#include <wrl.h>

MIDL_INTERFACE("45D64A29-A63E-4CB6-B498-5781D298CB4F")
ICoreWindowInteropLocal : public IUnknown
{
public:
    virtual STDMETHODIMP get_WindowHandle(HWND* hwnd) PURE;
    virtual STDMETHODIMP put_MessageHandled(boolean value) PURE;

    inline HWND GetWindowHandle() { HWND hwnd; get_WindowHandle(&hwnd); return hwnd; }
    __declspec(property(get = GetWindowHandle)) HWND WindowHandle;
    __declspec(property(put = put_MessageHandled)) boolean MessageHandled;
};

#if defined(__cplusplus_winrt)
template<typename T, typename U>
inline Microsoft::WRL::ComPtr<T> CastAsComPtr(U^ cxType)
{
    ComPtr<T> comPtr;
    reinterpret_cast<::IUnknown*>(cxType)->QueryInterface(comPtr.GetAddressOf());

    return comPtr;
}
#endif