///////////////////////////////////////////////////////////////////////////////
// SMPTE_TimecodeDriver.h

#ifndef __SMPTE_TIMECODEDRIVER_H__
#define __SMPTE_TIMECODEDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define SMPTE_TIMECODEDRV_NAME        "SMPTE_TIMECODE"
#define SMPTE_TIMECODEDRV_Major       1
#define SMPTE_TIMECODEDRV_Minor       0

#define DEVICE_CLASS CSMPTE_TimecodeDriver

#include "ObjDriver.h"

class CSMPTE_TimecodeDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl SMPTE_TIMECODEDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(SMPTE_TIMECODEDRV)
	VxD_Service( SMPTE_TIMECODEDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __SMPTE_TIMECODEDRIVER_H__