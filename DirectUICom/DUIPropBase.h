// DUIPropBase.h : CDUIPropBase ������

#pragma once
#include "resource.h"       // ������

#include "DirectUICom.h"
#include "_IDUIPropBaseEvents_CP.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif



// CDUIPropBase

class ATL_NO_VTABLE CDUIPropBase :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CDUIPropBase, &CLSID_DUIPropBase>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CDUIPropBase>,
	public CProxy_IDUIPropBaseEvents<CDUIPropBase>,
	public IDispatchImpl<IDUIPropBase, &IID_IDUIPropBase, &LIBID_DirectUIComLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CDUIPropBase()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DUIPROPBASE)


BEGIN_COM_MAP(CDUIPropBase)
	COM_INTERFACE_ENTRY(IDUIPropBase)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CDUIPropBase)
	CONNECTION_POINT_ENTRY(__uuidof(_IDUIPropBaseEvents))
END_CONNECTION_POINT_MAP()
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		m_comDUIPropType.CoCreateInstance(__uuidof(DUIPropType),NULL,CLSCTX_ALL);

		m_comDUIPropType->SetPropBase(this);

		return S_OK;
	}

	void FinalRelease()
	{
	}


public:
	CComPtr<IDUIPropType> m_comDUIPropType;

public:
	STDMETHOD(SetName)(BSTR strName);
	STDMETHOD(GetName)(BSTR* pResult);

	STDMETHOD(SetHelp)(BSTR strHelp);
	STDMETHOD(GetHelp)(BSTR* pResult);

	STDMETHOD(SetType)(enumPropType eType);
	STDMETHOD(GetType)(enumPropType* pResult);

	STDMETHOD(SetVariant)(VARIANT vt);
	STDMETHOD(GetVariant)(VARIANT* pResult);

	STDMETHOD(AccessConfig)(OLE_HANDLE pXmlEle,BSTR strKeyName,VARIANT_BOOL bRead,VARIANT_BOOL bCompleteUseKey,VARIANT_BOOL *pbResult);
	STDMETHOD(GetPropTypePtr)(IDUIPropType **ppDUIPropType);

};

OBJECT_ENTRY_AUTO(__uuidof(DUIPropBase), CDUIPropBase)
