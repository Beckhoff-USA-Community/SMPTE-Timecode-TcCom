// SMPTE_TimecodeCtrl.cpp : Implementation of CTcSMPTE_TimecodeCtrl
#include "TcPch.h"
#pragma hdrstop

#include "SMPTE_TimecodeW32.h"
#include "SMPTE_TimecodeCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CSMPTE_TimecodeCtrl

CSMPTE_TimecodeCtrl::CSMPTE_TimecodeCtrl() 
	: ITcOCFCtrlImpl<CSMPTE_TimecodeCtrl, CSMPTE_TimecodeClassFactory>() 
{
}

CSMPTE_TimecodeCtrl::~CSMPTE_TimecodeCtrl()
{
}

