// DUIPropBase.cpp : CDUIPropBase ��ʵ��

#include "stdafx.h"
#include "DUIPropBase.h"


// CDUIPropBase

STDMETHODIMP CDUIPropBase::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IDUIPropBase
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CDUIPropBase::SetName(BSTR strName)
{
	// TODO: �ڴ����ʵ�ִ���

	return S_OK;
}

STDMETHODIMP CDUIPropBase::GetName(BSTR* pResult)
{
	// TODO: �ڴ����ʵ�ִ���

	return S_OK;
}

STDMETHODIMP CDUIPropBase::SetHelp(BSTR strHelp)
{
	// TODO: �ڴ����ʵ�ִ���

	return S_OK;
}

STDMETHODIMP CDUIPropBase::GetHelp(BSTR* pResult)
{
	// TODO: �ڴ����ʵ�ִ���

	return S_OK;
}

STDMETHODIMP CDUIPropBase::SetType(enumPropType eType)
{
	// TODO: �ڴ����ʵ�ִ���

	return S_OK;
}

STDMETHODIMP CDUIPropBase::GetType(enumPropType* pResult)
{
	// TODO: �ڴ����ʵ�ִ���

	return S_OK;
}

STDMETHODIMP CDUIPropBase::SetVariant(VARIANT vt)
{
	// TODO: �ڴ����ʵ�ִ���

	return S_OK;
}

STDMETHODIMP CDUIPropBase::GetVariant(VARIANT* pResult)
{
	// TODO: �ڴ����ʵ�ִ���

	return S_OK;
}

STDMETHODIMP CDUIPropBase::AccessConfig(OLE_HANDLE pXmlEle,BSTR strKeyName,VARIANT_BOOL bRead,VARIANT_BOOL bCompleteUseKey,VARIANT_BOOL *pbResult)
{

	return S_OK;
}

STDMETHODIMP CDUIPropBase::GetPropTypePtr(IDUIPropType **ppDUIPropType)
{
	m_comDUIPropType->QueryInterface(ppDUIPropType);

	return S_OK;
}
