// DUIRenderImage.h : CDUIRenderImage ������

#pragma once
#include "resource.h"       // ������

#include "DirectUICom.h"
#include "_IDUIRenderImageEvents_CP.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif



// CDUIRenderImage

class ATL_NO_VTABLE CDUIRenderImage :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CDUIRenderImage, &CLSID_DUIRenderImage>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CDUIRenderImage>,
	public CProxy_IDUIRenderImageEvents<CDUIRenderImage>,
	public IDispatchImpl<IDUIRenderImage, &IID_IDUIRenderImage, &LIBID_DirectUIComLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CDUIRenderImage()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DUIRENDERIMAGE)


BEGIN_COM_MAP(CDUIRenderImage)
	COM_INTERFACE_ENTRY(IDUIRenderImage)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CDUIRenderImage)
	CONNECTION_POINT_ENTRY(__uuidof(_IDUIRenderImageEvents))
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

public:

};

OBJECT_ENTRY_AUTO(__uuidof(DUIRenderImage), CDUIRenderImage)
