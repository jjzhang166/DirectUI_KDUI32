// DUIObj.h : CDUIObj ������

#pragma once
#include "resource.h"       // ������

#include "DirectUICom.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif



// CDUIObj

class ATL_NO_VTABLE CDUIObj :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CDUIObj, &CLSID_DUIObj>,
	public ISupportErrorInfo,
	public IDispatchImpl<IDUIObj, &IID_IDUIObj, &LIBID_DirectUIComLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CDUIObj();
	virtual ~CDUIObj();

DECLARE_REGISTRY_RESOURCEID(IDR_DUIOBJ)


BEGIN_COM_MAP(CDUIObj)
	COM_INTERFACE_ENTRY(IDUIObj)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct();
	void FinalRelease();

public:
	CDUIObj_ *m_pDUIObj;
	IDUIRes* m_pDUIRes;

public:
	STDMETHOD(SetName)(BSTR strName);

	STDMETHOD(SetObjPtr)(OLE_HANDLE pObjPtr);
	STDMETHOD(GetObjPtr)(OLE_HANDLE* pObjPtr);

	STDMETHOD(GetName)(BSTR* pResult);
	STDMETHOD(GetType)(enumDUIObjType* pType);
	STDMETHOD(SetDUIRes)(IDUIRes* pDUIRes);
	STDMETHOD(GetDUIRes)(IDUIRes** ppResult);
};

OBJECT_ENTRY_AUTO(__uuidof(DUIObj), CDUIObj)
