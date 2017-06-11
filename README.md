BitBangUart
===========

This software is incomplete.

BitBanUart is a library for asynchronous serial communication using GPIO with a
small embedded CPU.

## Usage

    #include "bit_bang_uart.h"

    BitBangUart_Instance uart1;

    int main(void)
    {
        BitBangUart_Create(
            &uart1,
            BitBangUart_NumOfDataBit_8Bit,
            BitBangUart_ParityType_None,
            BitBangUart_StopBotLength_1Bit
        );

        EnableRxPinFallingInterrupt(); // Start Receiving.
    }

    // This function is called by RX pin falling edge interrupt.
    void RxPinDetectedStartBitFallingEdge(void)
    {
        BitBangUart_StartReceiving1Byte(&uart1);
        StartTimer();
        DisableRxPinFallingInterrupt();
    }

    // This function is called by timer interrupt.
    void TimerInterruptRxBitCenter(void)
    {
        if(BitBangUart_IsLastRxBit())
        {
            StopTimer();
            EnableRxPinFallingInterrupt();
        }

        bool bit = IsRxPinHigh();
        BitBangUart_Receive1Bit(&uart1, bit);
    }

## Document comments in source code.

Sorry. Document comments are written in Japanese. I am studying English.
Please tell me when you find any mistake in this project.
