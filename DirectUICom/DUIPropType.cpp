// DUIPropType.cpp : CDUIPropType ��ʵ��

#include "stdafx.h"
#include "DUIPropType.h"


// CDUIPropType

STDMETHODIMP CDUIPropType::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IDUIPropType
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CDUIPropType::get_eType(enumPropType* pVal)
{
	// TODO: �ڴ����ʵ�ִ���

	return S_OK;
}

STDMETHODIMP CDUIPropType::put_eType(enumPropType newVal)
{
	// TODO: �ڴ����ʵ�ִ���

	return S_OK;
}

STDMETHODIMP CDUIPropType::get_strName(BSTR* pVal)
{
	// TODO: �ڴ����ʵ�ִ���

	return S_OK;
}

STDMETHODIMP CDUIPropType::put_strName(BSTR newVal)
{
	// TODO: �ڴ����ʵ�ִ���

	return S_OK;
}

STDMETHODIMP CDUIPropType::get_vtValue(VARIANT* pVal)
{
	// TODO: �ڴ����ʵ�ִ���

	return S_OK;
}

STDMETHODIMP CDUIPropType::put_vtValue(VARIANT newVal)
{
	// TODO: �ڴ����ʵ�ִ���

	return S_OK;
}

STDMETHODIMP CDUIPropType::get_strValue(BSTR* pVal)
{
	// TODO: �ڴ����ʵ�ִ���

	return S_OK;
}

STDMETHODIMP CDUIPropType::put_strValue(BSTR newVal)
{
	// TODO: �ڴ����ʵ�ִ���

	return S_OK;
}

STDMETHODIMP CDUIPropType::GetPropBase(IDUIPropBase** pResult)
{
	// TODO: �ڴ����ʵ�ִ���

	return S_OK;
}

STDMETHODIMP CDUIPropType::SetPropBase(IDUIPropBase* pPropBase)
{
	// TODO: �ڴ����ʵ�ִ���

	return S_OK;
}

STDMETHODIMP CDUIPropType::GetParentProp(ICtrlPluginProp** pResult)
{
	// TODO: �ڴ����ʵ�ִ���

	return S_OK;
}

STDMETHODIMP CDUIPropType::SetParentProp(ICtrlPluginProp* pProp)
{
	// TODO: �ڴ����ʵ�ִ���

	return S_OK;
}

STDMETHODIMP CDUIPropType::get_bAccess(VARIANT_BOOL *pVal)
{
	return S_OK;
}

STDMETHODIMP CDUIPropType::put_bAccess(VARIANT_BOOL newVal)
{
	return S_OK;
}