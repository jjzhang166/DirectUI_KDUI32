// DUIRenderDC.h : CDUIRenderDC ������

#pragma once
#include "resource.h"       // ������

#include "DirectUICom.h"
#include "_IDUIRenderDCEvents_CP.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif



// CDUIRenderDC

class ATL_NO_VTABLE CDUIRenderDC :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CDUIRenderDC, &CLSID_DUIRenderDC>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CDUIRenderDC>,
	public CProxy_IDUIRenderDCEvents<CDUIRenderDC>,
	public IDispatchImpl<IDUIRenderDC, &IID_IDUIRenderDC, &LIBID_DirectUIComLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CDUIRenderDC():
	  m_pDC(NULL)
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DUIRENDERDC)


BEGIN_COM_MAP(CDUIRenderDC)
	COM_INTERFACE_ENTRY(IDUIRenderDC)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CDUIRenderDC)
	CONNECTION_POINT_ENTRY(__uuidof(_IDUIRenderDCEvents))
END_CONNECTION_POINT_MAP()
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

private:
	IRenderDC_ *m_pDC;

public:
	STDMETHOD(SetRenderDCPtr)(OLE_HANDLE pRenderDC);
	STDMETHOD(GetRenderDCPtr)(OLE_HANDLE *pRenderDC);


};

OBJECT_ENTRY_AUTO(__uuidof(DUIRenderDC), CDUIRenderDC)
