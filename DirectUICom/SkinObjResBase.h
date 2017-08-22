// SkinObjResBase.h : CSkinObjResBase ������

#pragma once
#include "resource.h"       // ������

#include "DirectUICom.h"
#include "DirectUISupport.h"

#include "_ISkinObjResBaseEvents_CP.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif



// CSkinObjResBase

class ATL_NO_VTABLE CSkinObjResBase :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CSkinObjResBase, &CLSID_SkinObjResBase>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CSkinObjResBase>,
	public CProxy_ISkinObjResBaseEvents<CSkinObjResBase>,
	public IDispatchImpl<ISkinObjResBase, &IID_ISkinObjResBase, &LIBID_DirectUIComLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CSkinObjResBase();
	virtual ~CSkinObjResBase();

DECLARE_REGISTRY_RESOURCEID(IDR_SKINOBJRESBASE)


BEGIN_COM_MAP(CSkinObjResBase)
	COM_INTERFACE_ENTRY(ISkinObjResBase)
	COM_INTERFACE_ENTRY(IDUIObj)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CSkinObjResBase)
	CONNECTION_POINT_ENTRY(__uuidof(_ISkinObjResBaseEvents))
END_CONNECTION_POINT_MAP()
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct();
	void FinalRelease();

public:
	IDUIObj *m_pDUIObj;
	SkinObjResBase_ *m_pSkinObjResBase;

public:
	INTERFACE_DUIOBJ_IMPL_DEFAULT(m_pDUIObj)

	STDMETHOD(SetObjPtr)(OLE_HANDLE pObjPtr);

	///////////////////////////////////////////////////////////////
	STDMETHOD(SetRect)(SkinRect rect);
	STDMETHOD(GetRect)(SkinRect *pRect);


};

OBJECT_ENTRY_AUTO(__uuidof(SkinObjResBase), CSkinObjResBase)
