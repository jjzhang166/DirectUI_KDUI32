// DirectUICom.cpp : DLL ������ʵ�֡�


#include "stdafx.h"
#include "resource.h"
#include "DirectUICom.h"
#include "dlldatax.h"

 
class CDirectUIComModule : public CAtlDllModuleT< CDirectUIComModule >
{
public :
	DECLARE_LIBID(LIBID_DirectUIComLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DIRECTUICOM, "{1007DC10-D48A-407F-A8C2-9ACA8AF38EB0}")
};

CDirectUIComModule _AtlModule;


#ifdef _MANAGED
#pragma managed(push, off)
#endif

// DLL ��ڵ�
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
#ifdef _MERGE_PROXYSTUB
    if (!PrxDllMain(hInstance, dwReason, lpReserved))
        return FALSE;
#endif
	hInstance;
    return _AtlModule.DllMain(dwReason, lpReserved); 
}

#ifdef _MANAGED
#pragma managed(pop)
#endif




// ����ȷ�� DLL �Ƿ���� OLE ж��
STDAPI DllCanUnloadNow(void)
{
#ifdef _MERGE_PROXYSTUB
    HRESULT hr = PrxDllCanUnloadNow();
    if (hr != S_OK)
        return hr;
#endif
    return _AtlModule.DllCanUnloadNow();
}


// ����һ���๤���Դ������������͵Ķ���
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
#ifdef _MERGE_PROXYSTUB
    if (PrxDllGetClassObject(rclsid, riid, ppv) == S_OK)
        return S_OK;
#endif
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - ������ӵ�ϵͳע���
STDAPI DllRegisterServer(void)
{
    // ע��������Ϳ�����Ϳ��е����нӿ�
    HRESULT hr = _AtlModule.DllRegisterServer();
#ifdef _MERGE_PROXYSTUB
    if (FAILED(hr))
        return hr;
    hr = PrxDllRegisterServer();
#endif
	return hr;
}


// DllUnregisterServer - �����ϵͳע������Ƴ�
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer();
#ifdef _MERGE_PROXYSTUB
    if (FAILED(hr))
        return hr;
    hr = PrxDllRegisterServer();
    if (FAILED(hr))
        return hr;
    hr = PrxDllUnregisterServer();
#endif
	return hr;
}


IDUIRes *g_pDUIRes = NULL;

IDUIRes* OpenUI()
{
	if (g_pDUIRes != NULL) return g_pDUIRes;

	::CoInitializeEx(NULL,COINIT_APARTMENTTHREADED);
	::CoCreateInstance(  __uuidof(DUIRes), NULL, CLSCTX_INPROC_SERVER, IID_IDispatch, (void**)&g_pDUIRes);
	if (g_pDUIRes == NULL) return NULL;

	VARIANT_BOOL bResult = VARIANT_FALSE;
	g_pDUIRes->OpenSkin(&bResult);

	return g_pDUIRes;
}

void CloseUI()
{
	VARIANT_BOOL bResult = VARIANT_FALSE;
	g_pDUIRes->CloseSkin(&bResult);
	g_pDUIRes->Release();
	g_pDUIRes = NULL;

	CoUninitialize(); 
}


