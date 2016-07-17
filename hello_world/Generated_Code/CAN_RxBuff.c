/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : CAN_RxBuff.c
**     Project     : hello_world
**     Processor   : MK70FN1M0VMJ12
**     Component   : RingBuffer
**     Version     : Component 01.046, Driver 01.00, CPU db: 3.00.000
**     Repository  : My Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-07-17, 01:40, # CodeGen: 1
**     Abstract    :
**         This component implements a ring buffer for different integer data type.
**     Settings    :
**          Component name                                 : CAN_RxBuff
**          SDK                                            : KSDK1
**          Reentrant                                      : yes
**          Critical Section                               : CS2
**          Buffer Size                                    : 64
**          Element Size                                   : 1 Byte
**     Contents    :
**         Clear           - void CAN_RxBuff_Clear(void);
**         Put             - uint8_t CAN_RxBuff_Put(CAN_RxBuff_ElementType elem);
**         Putn            - uint8_t CAN_RxBuff_Putn(CAN_RxBuff_ElementType *elem, CAN_RxBuff_BufSizeType...
**         Get             - uint8_t CAN_RxBuff_Get(CAN_RxBuff_ElementType *elemP);
**         Peek            - uint8_t CAN_RxBuff_Peek(CAN_RxBuff_BufSizeType index, CAN_RxBuff_ElementType...
**         Compare         - uint8_t CAN_RxBuff_Compare(CAN_RxBuff_BufSizeType index,...
**         Delete          - uint8_t CAN_RxBuff_Delete(void);
**         NofElements     - CAN_RxBuff_BufSizeType CAN_RxBuff_NofElements(void);
**         NofFreeElements - CAN_RxBuff_BufSizeType CAN_RxBuff_NofFreeElements(void);
**         Deinit          - void CAN_RxBuff_Deinit(void);
**         Init            - void CAN_RxBuff_Init(void);
**
**     License   :  Open Source (LGPL)
**     Copyright : (c) Copyright Erich Styger, 2014-2015, all rights reserved.
**     Web: http://www.mcuoneclipse.com
**     This an open source software of an embedded component for Processor Expert.
**     This is a free software and is opened for education,  research  and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file CAN_RxBuff.c
** @version 01.00
** @brief
**         This component implements a ring buffer for different integer data type.
*/         
/*!
**  @addtogroup CAN_RxBuff_module CAN_RxBuff module documentation
**  @{
*/         

/* MODULE CAN_RxBuff. */

#include "CAN_RxBuff.h"

#if CAN_RxBuff_IS_REENTRANT
  #define CAN_RxBuff_DEFINE_CRITICAL() CS2_CriticalVariable()
  #define CAN_RxBuff_ENTER_CRITICAL()  CS2_EnterCritical()
  #define CAN_RxBuff_EXIT_CRITICAL()   CS2_ExitCritical()
#else
  #define CAN_RxBuff_DEFINE_CRITICAL() /* nothing */
  #define CAN_RxBuff_ENTER_CRITICAL()  /* nothing */
  #define CAN_RxBuff_EXIT_CRITICAL()   /* nothing */
#endif
static CAN_RxBuff_ElementType CAN_RxBuff_buffer[CAN_RxBuff_BUF_SIZE]; /* ring buffer */
static CAN_RxBuff_BufSizeType CAN_RxBuff_inIdx;  /* input index */
static CAN_RxBuff_BufSizeType CAN_RxBuff_outIdx; /* output index */
static CAN_RxBuff_BufSizeType CAN_RxBuff_inSize; /* size data in buffer */
/*
** ===================================================================
**     Method      :  CAN_RxBuff_Put (component RingBuffer)
**     Description :
**         Puts a new element into the buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**         elem            - New element to be put into the buffer
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t CAN_RxBuff_Put(CAN_RxBuff_ElementType elem)
{
  uint8_t res = ERR_OK;
  CAN_RxBuff_DEFINE_CRITICAL();

  CAN_RxBuff_ENTER_CRITICAL();
  if (CAN_RxBuff_inSize==CAN_RxBuff_BUF_SIZE) {
    res = ERR_TXFULL;
  } else {
    CAN_RxBuff_buffer[CAN_RxBuff_inIdx] = elem;
    CAN_RxBuff_inIdx++;
    if (CAN_RxBuff_inIdx==CAN_RxBuff_BUF_SIZE) {
      CAN_RxBuff_inIdx = 0;
    }
    CAN_RxBuff_inSize++;
  }
  CAN_RxBuff_EXIT_CRITICAL();
  return res;
}

/*
** ===================================================================
**     Method      :  CAN_RxBuff_Putn (component RingBuffer)
**     Description :
**         Put a number new element into the buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * elem            - Pointer to new elements to be put into
**                           the buffer
**         nof             - number of elements
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t CAN_RxBuff_Putn(CAN_RxBuff_ElementType *elem, CAN_RxBuff_BufSizeType nof)
{
  uint8_t res = ERR_OK;

  while(nof>0) {
    res = CAN_RxBuff_Put(*elem);
    if (res!=ERR_OK) {
      break;
    }
    elem++; nof--;
  }
  return res;
}

/*
** ===================================================================
**     Method      :  CAN_RxBuff_Get (component RingBuffer)
**     Description :
**         Removes an element from the buffer
**     Parameters  :
**         NAME            - DESCRIPTION
**       * elemP           - Pointer to where to store the received
**                           element
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t CAN_RxBuff_Get(CAN_RxBuff_ElementType *elemP)
{
  uint8_t res = ERR_OK;
  CAN_RxBuff_DEFINE_CRITICAL();

  CAN_RxBuff_ENTER_CRITICAL();
  if (CAN_RxBuff_inSize==0) {
    res = ERR_RXEMPTY;
  } else {
    *elemP = CAN_RxBuff_buffer[CAN_RxBuff_outIdx];
    CAN_RxBuff_inSize--;
    CAN_RxBuff_outIdx++;
    if (CAN_RxBuff_outIdx==CAN_RxBuff_BUF_SIZE) {
      CAN_RxBuff_outIdx = 0;
    }
  }
  CAN_RxBuff_EXIT_CRITICAL();
  return res;
}

/*
** ===================================================================
**     Method      :  CAN_RxBuff_NofElements (component RingBuffer)
**     Description :
**         Returns the actual number of elements in the buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of elements in the buffer.
** ===================================================================
*/
CAN_RxBuff_BufSizeType CAN_RxBuff_NofElements(void)
{
  return CAN_RxBuff_inSize;
}

/*
** ===================================================================
**     Method      :  CAN_RxBuff_NofFreeElements (component RingBuffer)
**     Description :
**         Returns the actual number of free elements/space in the
**         buffer.
**     Parameters  : None
**     Returns     :
**         ---             - Number of elements in the buffer.
** ===================================================================
*/
CAN_RxBuff_BufSizeType CAN_RxBuff_NofFreeElements(void)
{
  return (CAN_RxBuff_BufSizeType)(CAN_RxBuff_BUF_SIZE-CAN_RxBuff_inSize);
}

/*
** ===================================================================
**     Method      :  CAN_RxBuff_Init (component RingBuffer)
**     Description :
**         Initializes the data structure
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void CAN_RxBuff_Init(void)
{
  CAN_RxBuff_inIdx = 0;
  CAN_RxBuff_outIdx = 0;
  CAN_RxBuff_inSize = 0;
}

/*
** ===================================================================
**     Method      :  CAN_RxBuff_Clear (component RingBuffer)
**     Description :
**         Clear (empty) the ring buffer.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void CAN_RxBuff_Clear(void)
{
  CAN_RxBuff_DEFINE_CRITICAL();

  CAN_RxBuff_ENTER_CRITICAL();
  CAN_RxBuff_Init();
  CAN_RxBuff_EXIT_CRITICAL();
}

/*
** ===================================================================
**     Method      :  CAN_RxBuff_Peek (component RingBuffer)
**     Description :
**         Returns an element of the buffer without removiing it.
**     Parameters  :
**         NAME            - DESCRIPTION
**         index           - Index of element. 0 peeks the top
**                           element, 1 the next, and so on.
**       * elemP           - Pointer to where to store the received
**                           element
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t CAN_RxBuff_Peek(CAN_RxBuff_BufSizeType index, CAN_RxBuff_ElementType *elemP)
{
  uint8_t res = ERR_OK;
  int idx; /* index inside ring buffer */
  CAN_RxBuff_DEFINE_CRITICAL();

  CAN_RxBuff_ENTER_CRITICAL();
  if (index>=CAN_RxBuff_BUF_SIZE) {
    res = ERR_OVERFLOW; /* asking for an element outside of ring buffer size */
  } else if (index<CAN_RxBuff_inSize) {
    idx = (CAN_RxBuff_outIdx+index)%CAN_RxBuff_BUF_SIZE;
    *elemP = CAN_RxBuff_buffer[idx];
  } else { /* asking for an element which does not exist */
    res = ERR_RXEMPTY;
  }
  CAN_RxBuff_EXIT_CRITICAL();
  return res;
}

/*
** ===================================================================
**     Method      :  CAN_RxBuff_Compare (component RingBuffer)
**     Description :
**         Compares the elements in the buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**         index           - Index of element. 0 peeks the top
**                           element, 1 the next, and so on.
**       * elemP           - Pointer to elements to compare with
**         nof             - number of elements to compare
**     Returns     :
**         ---             - zero if elements are the same, -1 otherwise
** ===================================================================
*/
uint8_t CAN_RxBuff_Compare(CAN_RxBuff_BufSizeType index, CAN_RxBuff_ElementType *elemP, CAN_RxBuff_BufSizeType nof)
{
  uint8_t cmpResult = 0;
  uint8_t res;
  CAN_RxBuff_ElementType val;

  while(nof>0) {
    res = CAN_RxBuff_Peek(index, &val);
    if (res!=ERR_OK) { /* general failure? */
      cmpResult = (uint8_t)-1; /* no match */
      break;
    }
    if (val!=*elemP) { /* mismatch */
      cmpResult = (uint8_t)-1; /* no match */
      break;
    }
    elemP++; index++; nof--;
  }

  return cmpResult;
}

/*
** ===================================================================
**     Method      :  CAN_RxBuff_Deinit (component RingBuffer)
**     Description :
**         Driver de-initialization
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/**
void CAN_RxBuff_Deinit(void)
{
  ** Function is implemented as macro in the header file
}
*/
/*
** ===================================================================
**     Method      :  CAN_RxBuff_Delete (component RingBuffer)
**     Description :
**         Removes an element from the buffer
**     Parameters  : None
**     Returns     :
**         ---             - Error code
** ===================================================================
*/
uint8_t CAN_RxBuff_Delete(void)
{
  uint8_t res = ERR_OK;
  CAN_RxBuff_DEFINE_CRITICAL();

  CAN_RxBuff_ENTER_CRITICAL();
  if (CAN_RxBuff_inSize==0) {
    res = ERR_RXEMPTY;
  } else {
    CAN_RxBuff_inSize--;
    CAN_RxBuff_outIdx++;
    if (CAN_RxBuff_outIdx==CAN_RxBuff_BUF_SIZE) {
      CAN_RxBuff_outIdx = 0;
    }
  }
  CAN_RxBuff_EXIT_CRITICAL();
  return res;
}

/* END CAN_RxBuff. */

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
