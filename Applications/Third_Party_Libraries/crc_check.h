/**
 * @author  RoboMaster
 * @date    2017-10
 * @file    crc_check.h
 * @brief   CRC check for referee system and tx2
 * @log     2018-04-18 nickelliang
 */

#ifndef _CRC_CHECK_H_
#define _CRC_CHECK_H_

#include "stm32f4xx_hal.h"

#define UP_REG_ID                   0xA0   // UP regional id
#define DN_REG_ID                   0xA5   // DOWN regional id
#define HEADER_LEN                  sizeof(frame_header_t)
#define CMD_LEN                     2      // CMDID bytes
#define CRC_LEN                     2      // CRC16 bytes

/* @note this is not used in this lib */
#define PROTOCAL_FRAME_MAX_SIZE     200

typedef struct {
  uint8_t  sof;
  uint16_t data_length;
  uint8_t  seq;
  uint8_t  crc8;
}  __packed frame_header_t;

/**
 * CRC8 checksum calculation
 *
 * @param  pchMessage Message to check
 * @param  dwLength   Length of the message
 * @param  ucCRC8     Initialized checksum
 * @return            CRC checksum
 */
static uint8_t get_crc8_check_sum(uint8_t* pchMessage, uint16_t dwLength, uint8_t ucCRC8);

/**
 * Verify CRC8
 *
 * @param  pchMessage Message to verify
 * @param  dwLength   Length = Data + Checksum
 * @return            1 for true, 0 for false
 */
uint8_t verify_crc8_check_sum(uint8_t* pchMessage, uint16_t dwLength);

/**
 * Append CRC8 to the end of message
 *
 * @param  pchMessage Message to calculate CRC and append
 * @param  dwLength   Length = Data + Checksum
 */
void append_crc8_check_sum(uint8_t* pchMessage, uint16_t dwLength);

/**
 * CRC16 checksum calculation
 *
 * @param  pchMessage Message to check
 * @param  dwLength   Length of the message
 * @param  wCRC       Initialized checksum
 * @return            CRC checksum
 */
static uint16_t get_crc16_check_sum(uint8_t* pchMessage, uint32_t dwLength, uint16_t wCRC);

/**
 * Verify CRC16
 *
 * @param  pchMessage Message to verify
 * @param  dwLength   Length = Data + Checksum
 * @return            1 for true, 0 for false
 */
uint8_t verify_crc16_check_sum(uint8_t* pchMessage, uint32_t dwLength);

/**
 * Append CRC16 to the end of message
 *
 * @param  pchMessage Message to calculate CRC and append
 * @param  dwLength   Length = Data + Checksum
 */
void append_crc16_check_sum(uint8_t* pchMessage, uint32_t dwLength);

#endif
