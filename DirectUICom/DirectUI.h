// DirectUI.h : CDirectUI ������

#pragma once
#include "resource.h"       // ������

#include "DirectUICom.h"
#include "DirectUISupport.h"

#include "_IDirectUIEvents_CP.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif



// CDirectUI

class ATL_NO_VTABLE CDirectUI :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CDirectUI, &CLSID_DirectUI>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CDirectUI>,
	public CProxy_IDirectUIEvents<CDirectUI>,
	public IDispatchImpl<IDirectUI, &IID_IDirectUI, &LIBID_DirectUIComLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CDirectUI();
	virtual ~CDirectUI();

DECLARE_REGISTRY_RESOURCEID(IDR_DIRECTUI)


BEGIN_COM_MAP(CDirectUI)
	COM_INTERFACE_ENTRY(IDirectUI)
	COM_INTERFACE_ENTRY(ISkinObjResBase)
	COM_INTERFACE_ENTRY(IDUIObj)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CDirectUI)
	CONNECTION_POINT_ENTRY(__uuidof(_IDirectUIEvents))
END_CONNECTION_POINT_MAP()
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct();
	void FinalRelease();

public:
	CDirectUI_  *m_pObject;

public:
	DECLARE_OBJRESBASE();

	STDMETHOD(SetObjPtr)(OLE_HANDLE pObjPtr);
	STDMETHOD(Create)(OLE_HANDLE hWnd,SkinRect rect,VARIANT_BOOL* pbResult);
	STDMETHOD(GetHwnd)(OLE_HANDLE * phResult);
};

OBJECT_ENTRY_AUTO(__uuidof(DirectUI), CDirectUI)
