///////////////////////////////////////////////////////////////////////////////
// Timecode_Receiver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "Timecode_Receiver.h"
#include "SMPTE_TimecodeVersion.h"
#include "TcStructuredExceptionHandling.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
DEFINE_THIS_FILE()

///////////////////////////////////////////////////////////////////////////////
// CTimecode_Receiver
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Collection of interfaces implemented by module CTimecode_Receiver
BEGIN_INTERFACE_MAP(CTimecode_Receiver)
	INTERFACE_ENTRY_ITCOMOBJECT()
///<AutoGeneratedContent id="InterfaceMap">
	INTERFACE_ENTRY(IID_ITComOnlineChange, ITComOnlineChange)
	INTERFACE_ENTRY(IID_ITcCyclic, ITcCyclic)
///</AutoGeneratedContent>
END_INTERFACE_MAP()

IMPLEMENT_IPERSIST_LIB(CTimecode_Receiver, VID_SMPTE_Timecode, CID_SMPTE_TimecodeCTimecode_Receiver)
IMPLEMENT_ITCOMOBJECT(CTimecode_Receiver)
IMPLEMENT_ITCOMOBJECT_SETSTATE_LOCKOP2(CTimecode_Receiver)


///////////////////////////////////////////////////////////////////////////////
// Set parameters of CTimecode_Receiver 
BEGIN_SETOBJPARA_MAP(CTimecode_Receiver)
///<AutoGeneratedContent id="SetObjectParameterMap">
	SETOBJPARA_VALUE(PID_TcTraceLevel, m_TraceLevelMax)
///</AutoGeneratedContent>
END_SETOBJPARA_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get parameters of CTimecode_Receiver 
BEGIN_GETOBJPARA_MAP(CTimecode_Receiver)
///<AutoGeneratedContent id="GetObjectParameterMap">
	GETOBJPARA_VALUE(PID_TcTraceLevel, m_TraceLevelMax)
///</AutoGeneratedContent>
END_GETOBJPARA_MAP()


///////////////////////////////////////////////////////////////////////////////
CTimecode_Receiver::CTimecode_Receiver()
	: m_Trace(m_TraceLevelMax, m_spSrv)
{
///<AutoGeneratedContent id="MemberInitialization">
	m_TraceLevelMax = tlAlways;
	m_pInputs = NULL;
	m_pOutputs = NULL;
///</AutoGeneratedContent>
}

///////////////////////////////////////////////////////////////////////////////
CTimecode_Receiver::~CTimecode_Receiver() 
{
}


///////////////////////////////////////////////////////////////////////////////
// State Transitions 
///////////////////////////////////////////////////////////////////////////////
IMPLEMENT_ITCOMOBJECT_SETOBJSTATE_IP_PI(CTimecode_Receiver)

///////////////////////////////////////////////////////////////////////////////
// State transition from PREOP to SAFEOP
//
// Initialize input parameters 
// Allocate memory
HRESULT CTimecode_Receiver::SetObjStatePS(PTComInitDataHdr pInitData)
{
	m_Trace.Log(tlVerbose, FENTERA);
	HRESULT hr = S_OK;
	IMPLEMENT_ITCOMOBJECT_EVALUATE_INITDATA(pInitData);

	// query TcCOM object server for ITcADI interface with own object id, 
	// which retrieves a reference to the TMC module instance handler
	m_spADI.SetOID(m_objId);
	hr = FAILED(hr) ? hr : m_spSrv->TcQuerySmartObjectInterface(m_spADI);

	// TODO: Add initialization code

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from SAFEOP to OP
//
// Register with other TwinCAT objects
HRESULT CTimecode_Receiver::SetObjStateSO()
{
	m_Trace.Log(tlVerbose, FENTERA);
	HRESULT hr = S_OK;

	// Retrieve pointer to data areas via ITcADI interface from TMC module handler
///<AutoGeneratedContent id="DataAreaPointerInitialization">
	hr = FAILED(hr) ? hr : m_spADI->GetImagePtr(sizeof(Timecode_ReceiverInputs), 0, ADI_Timecode_ReceiverInputs, (PVOID*)(&m_pInputs));
	hr = FAILED(hr) ? hr : m_spADI->GetImagePtr(sizeof(Timecode_ReceiverOutputs), 0, ADI_Timecode_ReceiverOutputs, (PVOID*)(&m_pOutputs));
///</AutoGeneratedContent>

	// TODO: Add any additional initialization

	// Cleanup if transition failed at some stage
	if ( FAILED(hr) )
	{
		SetObjStateOS();
	}

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from OP to SAFEOP
HRESULT CTimecode_Receiver::SetObjStateOS()
{
	m_Trace.Log(tlVerbose, FENTERA);

	HRESULT hr = S_OK;

	// Release pointer to data areas via ITcADI interface from TMC module handler
///<AutoGeneratedContent id="DataAreaPointerRelease">
	safe_release_imgptr(m_spADI, m_pInputs);
	safe_release_imgptr(m_spADI, m_pOutputs);
///</AutoGeneratedContent>

	// TODO: Add any additional deinitialization

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from SAFEOP to PREOP
HRESULT CTimecode_Receiver::SetObjStateSP()
{
	HRESULT hr = S_OK;
	m_Trace.Log(tlVerbose, FENTERA);

	m_spADI = NULL;

	// TODO: Add deinitialization code

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///<AutoGeneratedContent id="ImplementationOf_ITComOnlineChange">
///////////////////////////////////////////////////////////////////////////////
// PrepareOnlineChange is called after this instance has been set to PREOP in non RT context. 
// Parameter ipOldObj refers to the currently active instance which is still in OP. 
// Retrieve parameter values that are not changed during OP via ipOldObj here.
// 
// Parameter pOldInfo refers to instance data which includes the libraryId and
// the module class id. This information can be used to implement switch from one 
// specific version to another.
HRESULT CTimecode_Receiver::PrepareOnlineChange(ITComObject* ipOldObj, TmcInstData* pOldInfo)
{
	HRESULT hr = S_OK;

	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// PerformOnlineChange is called after this instance has been set to SAFEOP in RT context.
// Parameter ipOldObj refers to old instance which is now in SAFEOP. 
// Allows to retrieve data after the last cyclic update of the old instance and
// before the first cyclic update of this instance.
HRESULT CTimecode_Receiver::PerformOnlineChange(ITComObject* ipOldObj, TmcInstData* pOldInfo)
{
	HRESULT hr = S_OK;
	
	return hr;
}
///</AutoGeneratedContent>


///<AutoGeneratedContent id="ImplementationOf_ITcCyclic">
HRESULT CTimecode_Receiver::CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context)
{
	HRESULT hr = S_OK;

	// TODO: Replace the sample with your cyclic code
	// Cylce time in nanoseconds, i.e. time between "begin of task" to next "begin of task" (configured information)
	hr = FAILED(hr) ? hr : ipTask->GetCycleTime(&m_TaskSysTime);

	// Check to see if the correct cycle time of 1ms has been set
	if (m_TaskSysTime / 1000000 != 1)
	{
		m_pOutputs->Timecode_Receiver_Status = 0x1;
	}
	else
	{
		TimecodeDecode();
	}
	
	return hr;
}
///</AutoGeneratedContent>

void CTimecode_Receiver::TimecodeDecode() {


	// Reset the Timecode Decoder
	if (Reset)
	{
		First_BitZero_Reach = false;
		Index_Tab_TimeCodeFrame = 1;
		Index_Tab_EL3702 = 102;
		Even = false;

		for (int i = 0; i < TimeCodeFrame; i++) {
			Tab_TimeCodeFrame[i] = 0;
		}

		init = false;
		Reset = false;
	}

	if (m_pInputs->Reset_Frame_Count) {
		if (!FrameCountResetFlag) {
			m_pOutputs->Frame_Count = 0;
			FrameCountResetFlag = true;
		}
	}
	else {
		FrameCountResetFlag = false;
	}


	TcTry {
		// We save the last 2 cycles
		for (int i = 0; i < OversamplingFactor; i++) {
			EL3702_Doublecycles[i] = EL3702_Doublecycles[i + 100];
		}
		for (int i = 0; i < OversamplingFactor; i++) {
			EL3702_Doublecycles[100 + i] = m_pInputs->EL3702_Sample[i];
		}

		//Now we create an ARRAY that show the binary code
		ConstantTime = 0;	// ConstantTime is the duration of a constant level of the analog signal, time between 2 edges
		for (int i = 0; i < 2 * OversamplingFactor; i++) {
			EL3702_DoublecyclesTrig[i] = 0;	//An array that provide only the edges of the analog signal, only in the last cycle
		}

		for (int i = Index_Tab_EL3702; i < (2 * OversamplingFactor); i++) {
			// The analog signal change of sign-- > there is an edge
			// We capture a sample that is 0 : It's also a new edge
			if (((EL3702_Doublecycles[i - 1] * EL3702_Doublecycles[i]) < 0) || (EL3702_Doublecycles[i - 1] != 0) && (EL3702_Doublecycles[i] == 0)) {
			
				EL3702_DoublecyclesTrig[i] = 1;
				// We have to wait a least the second edge to mesure
				if (LastEdge == 0)
				{
					LastEdge = i;
				} // Let's go ...

			ConstantTime = (i - LastEdge) * 10; // If  EL3702 Oversampling time = 10 �s
			LastEdge = i;

			if((ConstantTime < 330) && (ConstantTime != 0)  && (First_BitZero_Reach)) {	// It's part of a 1 signal
				// 330�s is a fix limit that match all frame rates : Minimum period is 400 �s at 30 fr/sec, maximum half period is 260 �s at 24 fr/sec
				
				if (First_BitZero_Reach) {
					if (!Even) { // First part of a 1 bit
						Index_Tab_EL3702 = i;
						Even = true;
					}
					else { // Second part of a 1 bit
						Tab_TimeCodeFrame[Index_Tab_TimeCodeFrame] = 1; // We save a 1 bit in an array 
						Index_Tab_TimeCodeFrame = Index_Tab_TimeCodeFrame + 1; // and manage this array
						Index_Tab_EL3702 = i; // This bit in Frame is already handled, we will continu from this sample
						Even = false;
					}
				}
			}
			else if (ConstantTime > 300) { // It's a 0 bit 
				First_BitZero_Reach = true; // One 0 bit had been detected. We are now able to mesure 1 bit
				if (Even) { // If we were in the first part of a 1 bit
					Even = false;
					m_pOutputs->Frame_Error = m_pOutputs->Frame_Error + 1; // Then this 1 bit is not finished and it's a Frame Error
				}
				Tab_TimeCodeFrame[Index_Tab_TimeCodeFrame] = 0; // We save a 1 bit in an array 
				Index_Tab_TimeCodeFrame = Index_Tab_TimeCodeFrame + 1; // and manage this array 
				Index_Tab_EL3702 = i; // This bit in Frame is already handled, we will continu from this sample 
				m_pOutputs->Frame_Rate = 1000000.0 / (ConstantTime * 80); //  We measure the frame Rate. 0 Signal = 1 bit. 80 bit / frame
			}
			}
		}


		Index_Tab_EL3702 = Index_Tab_EL3702 - OversamplingFactor + 1; //  +1 in order to do not take in consideration the last one we handled
		if (Index_Tab_EL3702 < 2) // There is a problem : We should be able to read an edge in the last cycle 
		{
			m_pOutputs->Index_Tab_EL3702_Error = m_pOutputs->Index_Tab_EL3702_Error + 1;
		}
		LastEdge = LastEdge - OversamplingFactor; //We will shift the array of the last 2 Oversampling cycle. Then the last Edge will be 100 samples before

		// We are looking for the SyncWord - Sequence 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1
		for (int i = 16; i < TimeCodeFrame; i++) { // Sync Word = 16 bits
		
			for (int j = 0; j < 16; j++) {
				SyncWordTemp[j] = Tab_TimeCodeFrame[i - 16 + j]; //  Part of the Array that contain all bits read from the Timecode Frame 
			}

			if (memcmp(&SyncWord, &SyncWordTemp, 16) == 0) { // We compare this part with the SycnWord
				if (i >= 80) // A SyncWord is found and all bits that are in this frame are available
				{
					memcpy(&LastTimeCodeFrame, &Tab_TimeCodeFrame + i - 80, 80); // We extract this TimeCode Frame from the complete array
					m_pOutputs->Frames_Units = LastTimeCodeFrame[0] * 1 + LastTimeCodeFrame[1] * 2 + LastTimeCodeFrame[2] * 4 + LastTimeCodeFrame[3] * 8;
					m_pOutputs->Frames_Tens = LastTimeCodeFrame[8] * 10 + LastTimeCodeFrame[9] * 20;

					m_pOutputs->Seconds_Units = LastTimeCodeFrame[16] * 1 + LastTimeCodeFrame[17] * 2 + LastTimeCodeFrame[18] * 4 + LastTimeCodeFrame[19] * 8;
					m_pOutputs->Seconds_Tens = LastTimeCodeFrame[24] * 10 + LastTimeCodeFrame[25] * 20 + LastTimeCodeFrame[26] * 40;

					m_pOutputs->Minutes_Units = LastTimeCodeFrame[32] * 1 + LastTimeCodeFrame[33] * 2 + LastTimeCodeFrame[34] * 4 + LastTimeCodeFrame[35] * 8;
					m_pOutputs->Minutes_Tens = LastTimeCodeFrame[40] * 10 + LastTimeCodeFrame[41] * 20 + LastTimeCodeFrame[42] * 40;

					m_pOutputs->Hours_Units = LastTimeCodeFrame[48] * 1 + LastTimeCodeFrame[49] * 2 + LastTimeCodeFrame[50] * 4 + LastTimeCodeFrame[51] * 8;
					m_pOutputs->Hours_Tens = LastTimeCodeFrame[56] * 10 + LastTimeCodeFrame[57] * 20;

					m_pOutputs->Frames = m_pOutputs->Frames_Tens + m_pOutputs->Frames_Units;
					m_pOutputs->Seconds = m_pOutputs->Seconds_Tens + m_pOutputs->Seconds_Units;
					m_pOutputs->Minutes = m_pOutputs->Minutes_Tens + m_pOutputs->Minutes_Units;
					m_pOutputs->Hours = m_pOutputs->Hours_Tens + m_pOutputs->Hours_Units;

					sprintf(m_pOutputs->Time_String, "%lu:%lu:%lu:%lu", m_pOutputs->Hours, m_pOutputs->Minutes,  m_pOutputs->Seconds, m_pOutputs->Frames);

					m_pOutputs->Frame_Count = m_pOutputs->Frame_Count + 1; // Number of frame read

					// Now, we suppress this TimeCode frame from the array of bit, and shift this array
					for (int h = 0; h < TimeCodeFrame - i; h++) {
						Tab_TimeCodeFrame[h] = Tab_TimeCodeFrame[h + i];
					}
				
					for (int h = TimeCodeFrame - i; h < TimeCodeFrame; h++) {
						Tab_TimeCodeFrame[h] = 0;
					}
				
					Index_Tab_TimeCodeFrame = Index_Tab_TimeCodeFrame - i; // Next bit in the frame will be place here now

					break;
				}
			}
		}
		// There is a problem : We should be able to catch a SyncWord in a so big array a Timecode bit. Normally a SyncWord each 80 bits
		if (Index_Tab_TimeCodeFrame > TimeCodeFrame) {
			m_pOutputs->Index_Tab_Timecode_Frame_Error = m_pOutputs->Index_Tab_Timecode_Frame_Error + 1;
			Reset = true;
		}

		m_pOutputs->Timecode_Receiver_Status = 0x2;

	}
	TcExcept(EXCEPTION_EXECUTE_HANDLER)
	{
		if (m_pOutputs->Timecode_Receiver_Status != 0x9)
		{
			m_Trace.Log(tlError, "Error processing SMPTE signal, check SMPTE sender is in sending state or bad cableing");
		}
		Reset = true;
		m_pOutputs->Timecode_Receiver_Status = 0x9;
	}


}
