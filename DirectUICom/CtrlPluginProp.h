// CtrlPluginProp.h : CCtrlPluginProp ������

#pragma once
#include "resource.h"       // ������

#include "DirectUICom.h"
#include "_ICtrlPluginPropEvents_CP.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif



// CCtrlPluginProp

class ATL_NO_VTABLE CCtrlPluginProp :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CCtrlPluginProp, &CLSID_CtrlPluginProp>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CCtrlPluginProp>,
	public CProxy_ICtrlPluginPropEvents<CCtrlPluginProp>,
	public IDispatchImpl<ICtrlPluginProp, &IID_ICtrlPluginProp, &LIBID_DirectUIComLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CCtrlPluginProp()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CTRLPLUGINPROP)


BEGIN_COM_MAP(CCtrlPluginProp)
	COM_INTERFACE_ENTRY(ICtrlPluginProp)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CCtrlPluginProp)
	CONNECTION_POINT_ENTRY(__uuidof(_ICtrlPluginPropEvents))
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


	BOOL IsExistedAddinProp(ICtrlPluginProp* pProp);
	BOOL IsExistedSkinProp(IDUIPropType* pProp);
	BOOL IsExistedPropBase(IDUIPropBase* pProp);

	BOOL AccessConfig(OLE_HANDLE pXmlEle,VARIANT_BOOL bRead,BSTR strName,
		IDUIPropType* pSkinPropType,VARIANT_BOOL *pbResult);

private:
	deque<ICtrlPluginProp*>	m_dequeProps;
	deque<IDUIPropType*>		m_dequeSubSkinProps;
	deque<IDUIPropBase*>		m_dequePropBases;
	ICtrlPluginProp					*m_pParent;
	VARIANT_BOOL					m_bGroup;
	CComBSTR							m_strName;
	VARIANT_BOOL					m_bExpand;

	CDUIResource_						*m_pDUIResource;

	IDUIRes								*m_pDUIRes;
	IDUIControlBase					*m_pControlBase;

	LPVOID								m_lpProp;

public:
	STDMETHOD(GetAddinPropByIndex)(/*[in]*/long nIndex,/*[out,retval]*/ICtrlPluginProp** pAddinProp);
	STDMETHOD(GetAddinPropCount)(/*[out,retval]*/long* plResult);
	STDMETHOD(GetSkinPropTypeFromIndex)(/*[in]*/long nIndex,/*[out,retval]*/IDUIPropType** pPropType);
	STDMETHOD(GetSkinPropTypeCount)(/*[out,retval]*/long* plResult);
	STDMETHOD(GetParent)(/*[out,retval]*/ICtrlPluginProp** pProp);
	STDMETHOD(SetParent)(/*[in]*/ICtrlPluginProp* pParent);
	STDMETHOD(IsExpand)(/*[out,retval]*/VARIANT_BOOL* pbResult);
	STDMETHOD(Expand)(/*[in]*/VARIANT_BOOL bExpand);
	STDMETHOD(AccessConfig)(/*[in]*/OLE_HANDLE pXmlEle,/*[in]*/VARIANT_BOOL bRead,/*[out,retval]*/VARIANT_BOOL* pbResult);
	STDMETHOD(RemoveProp)(ICtrlPluginProp* pSubProp);
	STDMETHOD(AddProp)(ICtrlPluginProp* pSubProp);
	STDMETHOD(RemoveSkinProp)(IDUIPropType* pSkinProp);
	STDMETHOD(AddSkinProp)(IDUIPropType* pSkinProp);
	STDMETHOD(get_strName)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_strName)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_bGroup)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_bGroup)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(GetDUIRes)(IDUIRes** ppDUIRes);
	STDMETHOD(SetDUIRes)(IDUIRes *pDUIRes);
	STDMETHOD(GetControlBasePtr)(IDUIControlBase **ppResult);
	STDMETHOD(SetControlBasePtr)(IDUIControlBase *pCtrlBase);
	STDMETHOD(AccessConfig2)(BSTR strParentName,OLE_HANDLE pXmlEle,VARIANT_BOOL bRead,VARIANT_BOOL* pbResult);
	STDMETHOD(AddPropBase)(IDUIPropBase* pProp);
	STDMETHOD(RemovePropBase)(IDUIPropBase* pProp);
	STDMETHOD(RemoveAllPropBase)();
	STDMETHOD(GetPropBaseCount)(LONG* pResult);
	STDMETHOD(GetAtPropBase)(LONG nIndex,IDUIPropBase** ppResult);
	STDMETHOD(AccessConfig3)(BSTR strParentName,OLE_HANDLE pXmlEle,VARIANT_BOOL bRead,VARIANT_BOOL* pbResult);

};

OBJECT_ENTRY_AUTO(__uuidof(CtrlPluginProp), CCtrlPluginProp)
