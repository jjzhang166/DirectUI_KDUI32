// DUIRes.h : CDUIRes ������

#pragma once
#include "resource.h"       // ������

#include "DirectUICom.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif



// CDUIRes

class ATL_NO_VTABLE CDUIRes :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CDUIRes, &CLSID_DUIRes>,
	public ISupportErrorInfo,
	public IDispatchImpl<IDUIRes, &IID_IDUIRes, &LIBID_DirectUIComLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CDUIRes();
	virtual ~CDUIRes();

DECLARE_REGISTRY_RESOURCEID(IDR_DUIRES)


BEGIN_COM_MAP(CDUIRes)
	COM_INTERFACE_ENTRY(IDUIRes)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct();
	void FinalRelease();

private:
	CDUIResource_ m_duiResource;

public:
	STDMETHOD(GetDUIResObjPtr)(OLE_HANDLE *plResObjPtr);
	STDMETHOD(OpenSkin)(VARIANT_BOOL *pbResult);
	STDMETHOD(CloseSkin)(VARIANT_BOOL *pbResult);
	STDMETHOD(CreateDirectUI)(OLE_HANDLE hWnd,IDirectUI **pResult);
	STDMETHOD(CreateControl)(IDirectUI* pDirectUI,BSTR strCLSID,IDUIControlBase **pResult);
	STDMETHOD(LoadImage)(BSTR strImagePath,IDUIRenderImage **ppResult);
};

OBJECT_ENTRY_AUTO(__uuidof(DUIRes), CDUIRes)
