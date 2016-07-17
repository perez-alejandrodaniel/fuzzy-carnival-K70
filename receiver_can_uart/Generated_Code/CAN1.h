/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : CAN1.h
**     Project     : receiver_can_uart
**     Processor   : MK70FN1M0VMJ12
**     Component   : CAN_LDD
**     Version     : Component 01.112, Driver 01.07, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-07-16, 21:16, # CodeGen: 2
**     Abstract    :
**         This component "CAN_LDD" implements a CAN serial channel.
**     Settings    :
**          Component name                                 : CAN1
**          CAN channel                                    : CAN1
**          Interrupt service                              : Enabled
**            Interrupt error                              : INT_CAN1_Error
**            Interrupt error priority                     : medium priority
**            Interrupt bus off                            : INT_CAN1_Bus_Off
**            Interrupt bus off priority                   : medium priority
**            Interrupt message buffers                    : INT_CAN1_ORed_Message_buffer
**            Interrupt message buffers priority           : medium priority
**            Interrupt Tx warning                         : INT_CAN1_Tx_Warning
**            Interrupt Tx warning priority                : medium priority
**            Interrupt Rx warning                         : INT_CAN1_Rx_Warning
**            Interrupt Rx warning priority                : medium priority
**            Interrupt wake up                            : INT_CAN1_Wake_Up
**            Interrupt wake up priority                   : medium priority
**          Settings                                       : 
**            Pins                                         : 
**              Rx pin                                     : 
**                Rx pin                                   : PTC16/CAN1_RX/UART3_RX/ENET0_1588_TMR0/FBa_CS5_b/FBa_TSIZ1/FBa_BE23_16_BLS15_8_b/NFC_RB
**                Rx pin signal                            : 
**              Tx pin                                     : 
**                Tx pin                                   : PTC17/CAN1_TX/UART3_TX/ENET0_1588_TMR1/FBa_CS4_b/FBa_TSIZ0/FBa_BE31_24_BLS7_0_b/NFC_CE0_b
**                Tx pin Signal                            : 
**            Global acceptance mask                       : no
**            Receiver FIFO                                : Disabled
**            Message buffers                              : 2
**              Buffer0                                    : 
**                Buffer type                              : Receive
**                  Accept frames                          : Standard
**                  Message ID                             : 0x100
**                  Invidual Acceptance Mask               : Enabled
**                    Acceptance Mask                      : 0x1FFFFFFF
**              Buffer1                                    : 
**                Buffer type                              : Transmit
**            Abort transmission mode                      : no
**            Remote request storing                       : Remote Request Frame is stored
**            Entire frame arbitration field comparison    : no
**            Local priority                               : no
**            Self reception                               : Disabled
**            Timer synchronization                        : Disabled
**            Lowest buffer transmitted first              : Lowest ID
**            Loop mode                                    : no
**            Bus off recovery mode                        : Automatic
**            Listen only mode                             : no
**            Wake up                                      : Disabled
**          Timing                                         : 
**            CAN timing calculator                        : click to run ->
**            Propagation segment                          : 3
**            Time segment 1                               : 4
**            Time segment 2                               : 2
**            Resync jump width                            : 1
**            Time quanta per bit                          : 10
**            Samples per bit                              : One sample
**            Bit rate                                     : 500 kbit/s
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnFreeTxBuffer                             : Enabled
**              OnFullRxBuffer                             : Enabled
**              OnTransmitWarning                          : Disabled
**              OnReceiveWarning                           : Disabled
**              OnBusOff                                   : Disabled
**              OnWakeUp                                   : Disabled
**              OnError                                    : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init          - LDD_TDeviceData* CAN1_Init(LDD_TUserData *UserDataPtr);
**         SetRxBufferID - LDD_TError CAN1_SetRxBufferID(LDD_TDeviceData *DeviceDataPtr,...
**         SendFrame     - LDD_TError CAN1_SendFrame(LDD_TDeviceData *DeviceDataPtr, LDD_CAN_TMBIndex...
**         ReadFrame     - LDD_TError CAN1_ReadFrame(LDD_TDeviceData *DeviceDataPtr, LDD_CAN_TMBIndex...
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file CAN1.h
** @version 01.07
** @brief
**         This component "CAN_LDD" implements a CAN serial channel.
*/         
/*!
**  @addtogroup CAN1_module CAN1 module documentation
**  @{
*/         

#ifndef __CAN1_H
#define __CAN1_H

/* MODULE CAN1. */

/* Include inherited beans */
#include "Cpu.h"


/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define CAN1_PRPH_BASE_ADDRESS  0x400A4000U
  
typedef struct {
  CAN_MemMapPtr BaseAddr;              /* Device register memory map base address */
  uint8_t MaxDataLen;                  /* Max number of data to be sent in one frame */
  LDD_CAN_TMBIndex MaxBufferIndex;     /* Number of message buffers */
  LDD_CAN_TMBIndex BuffersNumber;      /* Number of message buffers */
  LDD_CAN_TBufferMask RxBufferMask;    /* Bit mask for message buffers configured as receive */
  LDD_CAN_TBufferMask TxBufferMask;    /* Bit mask for message buffers configured as transmit */
  LDD_TUserData *UserData;             /* RTOS device data structure */
} CAN1_TDeviceData;

typedef CAN1_TDeviceData *CAN1_TDeviceDataPtr; /* Pointer to the device data structure. */

/*
** ===================================================================
**     Method      :  CAN1_Init (component CAN_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the "Enable
**         in init. code" is set to "yes" value then the device is also
**         enabled(see the description of the Enable() method). In this
**         case the Enable() method is not necessary and needn't to be
**         generated.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* CAN1_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  CAN1_SetRxBufferID (component CAN_LDD)
*/
/*!
**     @brief
**         Sets the ID of the receive message buffer specified by the
**         parameter BufferIdx.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         BufferIdx       - Index of the Rx message buffer.
**     @param
**         MessageID       - 11-bit Mask could be selected
**                           for a standard frame or 29-bit for an
**                           extended frame. 
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED - This component is disabled
**                           by user.
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_PARAM_RANGE - Value of message buffer
**                           index is out of range.
**                           ERR_PARAM_INDEX - Index of message buffer
**                           is not for data receive.
*/
/* ===================================================================*/
LDD_TError CAN1_SetRxBufferID(LDD_TDeviceData *DeviceDataPtr, LDD_CAN_TMBIndex BufferIdx, LDD_CAN_TMessageID MessageID);

/*
** ===================================================================
**     Method      :  CAN1_ReadFrame (component CAN_LDD)
*/
/*!
**     @brief
**         Reads a frame from the CAN device. The user is informed
**         about CAN reception through OnFullRxBuffer event or
**         GetStateRX method.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         BufferIdx       - Index of the Rx message buffer.
**     @param
**         Frame           - Pointer to the received CAN frame.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED - This component is disabled
**                           by user
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_PARAM_RANGE - Value of buffer index is
**                           out of range.
**                           ERR_PARAM_INDEX - Index of message buffer
**                           is not for receive.
**                           ERR_BUSY - CAN module is busy.
**                           ERR_RXEMPTY - The receive buffer is empty.
**                           ERR_OVERRUN - The receive buffer is overrun.
*/
/* ===================================================================*/
LDD_TError CAN1_ReadFrame(LDD_TDeviceData *DeviceDataPtr, LDD_CAN_TMBIndex BufferIdx, LDD_CAN_TFrame *Frame);

/*
** ===================================================================
**     Method      :  CAN1_SendFrame (component CAN_LDD)
*/
/*!
**     @brief
**         Sends a frame via the CAN device. This method allow to
**         specify CAN buffer number, message ID, data to be sent,
**         frame type and whether the message will be sent after the
**         request comes. 
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         BufferIdx       - Index of the Tx message buffer.
**     @param
**         Frame           - Pointer to the CAN frame to send.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED - This component is disabled
**                           by user
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_PARAM_RANGE - Value of buffer index is
**                           out of range.
**                           ERR_PARAM_INDEX - Index of message buffer
**                           is not for transmit.
**                           ERR_PARAM_LENGTH - Number of data in the
**                           frame is greater than MaxDataLength.
**                           ERR_PARAM_ATTRIBUTE_SET - Frame type isn't
**                           supported.
**                           ERR_PARAM_VALUE - Value of Tx priority is
**                           fail.
**                           ERR_BUSY - CAN module is busy.
*/
/* ===================================================================*/
LDD_TError CAN1_SendFrame(LDD_TDeviceData *DeviceDataPtr, LDD_CAN_TMBIndex BufferIdx, LDD_CAN_TFrame *Frame);

/*
** ===================================================================
**     Method      :  CAN1_InterruptRxTx (component CAN_LDD)
**
**     Description :
**         Or'ed Message Interrupt
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(CAN1_InterruptRxTx);

/*
** ===================================================================
**     Method      :  CAN1_InterruptTxWarn (component CAN_LDD)
**
**     Description :
**         Transmit Warning Interrupt
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(CAN1_InterruptTxWarn);

/*
** ===================================================================
**     Method      :  CAN1_InterruptRxWarn (component CAN_LDD)
**
**     Description :
**         Receive Warning Interrupt
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(CAN1_InterruptRxWarn);

/*
** ===================================================================
**     Method      :  CAN1_InterruptBusOff (component CAN_LDD)
**
**     Description :
**         Bus Off interrupt for CAN
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(CAN1_InterruptBusOff);

/*
** ===================================================================
**     Method      :  CAN1_InterruptError (component CAN_LDD)
**
**     Description :
**         Error Interrupt for CAN
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(CAN1_InterruptError);

/*
** ===================================================================
**     Method      :  CAN1_InterruptWakeUp (component CAN_LDD)
**
**     Description :
**         Wake Up Interrupt
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(CAN1_InterruptWakeUp);


/*
** ===================================================================
**     Method      :  CAN1_SetClockConfiguration (component CAN_LDD)
**
**     Description :
**         This method changes the clock configuration. During a clock 
**         configuration change the component changes it's setting 
**         immediately upon a request.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void CAN1_SetClockConfiguration(LDD_TDeviceData *DeviceDataPtr, LDD_TClockConfiguration ClockConfiguration);


/* END CAN1. */

#endif
/* ifndef __CAN1_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/