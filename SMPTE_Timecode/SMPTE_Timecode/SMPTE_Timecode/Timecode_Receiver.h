///////////////////////////////////////////////////////////////////////////////
// Timecode_Receiver.h
#pragma once

#include "SMPTE_TimecodeInterfaces.h"

class CTimecode_Receiver 
	: public ITComObject
///<AutoGeneratedContent id="InheritanceList">
	, public ITComOnlineChange
	, public ITcCyclic
///</AutoGeneratedContent>
{
public:
	DECLARE_IUNKNOWN()
	DECLARE_IPERSIST_LIB()
	DECLARE_ITCOMOBJECT_LOCKOP()

	CTimecode_Receiver();
	virtual	~CTimecode_Receiver();

///<AutoGeneratedContent id="InterfaceMembers">
	// ITComOnlineChange
	virtual HRESULT TCOMAPI PrepareOnlineChange(ITComObject* ipOldObj, TmcInstData* pOldInfo);
	virtual HRESULT TCOMAPI PerformOnlineChange(ITComObject* ipOldObj, TmcInstData* pOldInfo);

	// ITcCyclic
	virtual HRESULT TCOMAPI CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context);

///</AutoGeneratedContent>

protected:
	DECLARE_ITCOMOBJECT_SETSTATE();

	// Tracing
	CTcTrace m_Trace;

///<AutoGeneratedContent id="Members">
	TcTraceLevel m_TraceLevelMax;
	Timecode_ReceiverInputs* m_pInputs;
	Timecode_ReceiverOutputs* m_pOutputs;
///</AutoGeneratedContent>

	// Custom methods
	virtual void TCOMAPI TimecodeDecode();

	// Custom variables
	ITcADIPtr m_spADI;
	// For detecting the Task Cycle Time
	ULONG m_TaskSysTime;

	// SMPTE Decode Constants
	const static WORD OversamplingFactor = 100; // Defined by the TMC EL3702 Process Image
	const static WORD DoubleOversamplingFactor = 200; // OversamplingFactor x 2 
	const static WORD TimeCodeFrame = 300; //bits detected in the Timecode signal

	// SMPTE Decode variables
	SHORT EL3702_Doublecycles[DoubleOversamplingFactor];
	SHORT EL3702_DoublecyclesTrig[DoubleOversamplingFactor];
	BYTE Tab_TimeCodeFrame[TimeCodeFrame]; //Bit read in the frame
	BYTE LastTimeCodeFrame[80]; //Last and unique TimeCode Frame
	BYTE SyncWord[16] = { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 };
	BYTE SyncWordTemp[16];

	DWORD LastEdge;
	DWORD ConstantTime;
	BOOL Even; // Is use to mesure 2 half period to detect a bit 1
	BOOL FrameCountResetFlag = false; // Flag for rising edge reset trigger
	BOOL First_BitZero_Reach = false; // We can mesure only when we reach a first Bit 0 otherwise we do not know in which half period of a bit 1 we are 

	INT Index_Tab_EL3702 = 102;
	WORD Index_Tab_TimeCodeFrame = 1;

	BOOL init;
	BOOL Reset;
};
