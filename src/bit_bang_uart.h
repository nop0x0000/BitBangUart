/**
 * @file
 * BitBangUartの公開用ヘッダファイル
 *
 * @addtogroup BitBangUart
 * ハードウェア
 *
 * @{
 */
#ifndef BIT_BANG_UART_H
#define BIT_BANG_UART_H

#ifdef __cpluslplus
extern "C"
{
#endif

// includes(system) {{{
#include <stdint.h>
#include <stdbool.h>
// }}}

// includes(user) {{{
// }}}

// define macros {{{
// }}}

// define function macros {{{
// }}}

// typedefs {{{
// }}}

// enum definitions {{{
/** パリティの有無、種類 */
typedef enum
{
    BitBangUart_ParityType_None,
    BitBangUart_ParityType_Even,
    BitBangUart_ParityType_Odd,
} BitBangUart_ParityType;

/** 送信するデータのビット数 */
typedef enum
{
    BitBangUart_NumOfDataBit_7Bit = 7,
    BitBangUart_NumOfDataBit_8Bit,
    BitBangUart_NumOfDataBit_9Bit,
} BitBangUart_NumOfDataBit;

/** ストップビットの長さ */
typedef enum
{
    BitBangUart_StopBotLength_1Bit = 1,
    BitBangUart_StopBotLength_2Bit,
} BitBangUart_StopBitLength;
// }}}

// struct / union definitions {{{
typedef struct
{
} BitBangUart_Instance;
// }}}

// extern variables {{{
// }}}

// function prototypes {{{
/**
 * モジュールを初期化する
 */
void BitBangUart_Create(
        BitBangUart_Instance *     self,
        BitBangUart_NumOfDataBit   dataBits,
        BitBangUart_ParityType     parityType,
        BitBangUart_StopBitLength  stopBits
    );

/**
 * モジュールの後処理をする
 */
void BitBangUart_Destroy(BitBangUart_Instance * self);

/**
 * 1バイトの受信を開始する
 *
 * スタートビットの立下りを割り込みなどで検知したときに呼ぶこと
 */
bool BitBangUart_StartReceiving1Byte(BitBangUart_Instance * self);

/**
 * 1ビット受信処理
 *
 * @param bit スタートビット、データビット、(有ればパリティビット)、ストップビットの値を渡すこと
 * @return 1バイト受信が完了した場合falseを返す。
 */
bool BitBangUart_Receive1Bit(BitBangUart_Instance * self, bool bit);

/**
 * 受信したデータがあるかを取得する関数
 *
 * @return
 * 受信データ有り : trueを返す
 * 受信データなし : falseを返す
 */
bool BitBangUart_IsDataReceived(BitBanguart_Instance * self);

/**
 * 1バイト受信時に呼び出されるコールバック関数を設定する
 */
void BitBangUart_SetDataReceiveCallback(
        BitBangUart_Instance * self,
        void(* callback)(BitBangUart_Instance * self)
    );

/**
 * 受信したデータ読み込む関数
 */
uint8_t BitBangUart_Get(BitBangUart_Instance * self);
// }}}

// inline functions {{{
// }}}

#ifdef __cplusplus
}
#endif

#endif // BIT_BANG_UART_H
/** @} */
