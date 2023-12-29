///////////////////////////////////////////////////////////////////////////////
// SMPTE_TimecodeDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "SMPTE_TimecodeDriver.h"
#include "SMPTE_TimecodeClassFactory.h"

DECLARE_GENERIC_DEVICE(SMPTE_TIMECODEDRV)

IOSTATUS CSMPTE_TimecodeDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CSMPTE_TimecodeClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CSMPTE_TimecodeDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CSMPTE_TimecodeDriver::SMPTE_TIMECODEDRV_GetVersion( )
{
	return( (SMPTE_TIMECODEDRV_Major << 8) | SMPTE_TIMECODEDRV_Minor );
}

