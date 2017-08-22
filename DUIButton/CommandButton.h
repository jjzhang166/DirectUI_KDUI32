// CommandButton.h : CCommandButton ������

#pragma once
#include "resource.h"       // ������

#include "DUIButton.h"
#include "directuipluginsupport.h"

#include "_ICommandButtonEvents_CP.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif



// CCommandButton

class ATL_NO_VTABLE CCommandButton :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CCommandButton, &CLSID_CommandButton>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CCommandButton>,
	public CProxy_ICommandButtonEvents<CCommandButton>,
	public IDispatchImpl<ICommandButton, &IID_ICommandButton, &LIBID_DUIButtonLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CCommandButton();
	virtual ~CCommandButton();

DECLARE_REGISTRY_RESOURCEID(IDR_COMMANDBUTTON)


BEGIN_COM_MAP(CCommandButton)
	COM_INTERFACE_ENTRY(ICommandButton)
	COM_INTERFACE_ENTRY(IDUIControlBase)
	COM_INTERFACE_ENTRY(ISkinObjResBase)
	COM_INTERFACE_ENTRY(IDUIObj)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CCommandButton)
	CONNECTION_POINT_ENTRY(__uuidof(_ICommandButtonEvents))
END_CONNECTION_POINT_MAP()
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct();
	void FinalRelease();

private:
	_bstr_t m_strText;
	IImageSecProp *m_pImageBack[DUI_BUTTON_STATUS_LAST];

public:
	DECLARE_CONTROLBASE_NORENDERDRAWOBJECT()
	STDMETHOD(FinalCreate)(VARIANT_BOOL bNewObject);
	STDMETHOD(CreateProps)(VARIANT_BOOL* pbResult);
	STDMETHOD(RenderDrawObject)(IDUIRenderDC* pDC, SkinRect* rect, VARIANT_BOOL* pbResult);
	STDMETHOD(EventNotify)(DUINotify *peVentNotify,VARIANT_BOOL *pbResult);

	STDMETHOD(SetText)(BSTR strText,VARIANT_BOOL* pbResult);
	STDMETHOD(SetBackImage)(DUIImageBase *pImageBase,eDUI_BUTTON_STATUS eStatus,VARIANT_BOOL* pbResult);

};

OBJECT_ENTRY_AUTO(__uuidof(CommandButton), CCommandButton)
