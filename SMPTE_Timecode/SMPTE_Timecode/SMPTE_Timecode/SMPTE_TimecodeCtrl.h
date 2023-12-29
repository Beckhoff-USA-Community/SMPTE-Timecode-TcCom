///////////////////////////////////////////////////////////////////////////////
// SMPTE_TimecodeCtrl.h

#ifndef __SMPTE_TIMECODECTRL_H__
#define __SMPTE_TIMECODECTRL_H__

#include <atlbase.h>
#include <atlcom.h>


#include "resource.h"       // main symbols
#include "SMPTE_TimecodeW32.h"
#include "TcBase.h"
#include "SMPTE_TimecodeClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CSMPTE_TimecodeCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CSMPTE_TimecodeCtrl, &CLSID_SMPTE_TimecodeCtrl>
	, public ISMPTE_TimecodeCtrl
	, public ITcOCFCtrlImpl<CSMPTE_TimecodeCtrl, CSMPTE_TimecodeClassFactory>
{
public:
	CSMPTE_TimecodeCtrl();
	virtual ~CSMPTE_TimecodeCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_SMPTE_TIMECODECTRL)
DECLARE_NOT_AGGREGATABLE(CSMPTE_TimecodeCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CSMPTE_TimecodeCtrl)
	COM_INTERFACE_ENTRY(ISMPTE_TimecodeCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __SMPTE_TIMECODECTRL_H__
