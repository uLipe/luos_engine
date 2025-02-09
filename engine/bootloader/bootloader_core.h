/******************************************************************************
 * @file Bootloader
 * @brief Bootloader functionnalities for luos framework
 * @author Luos
 * @version 0.0.0
 ******************************************************************************/
#ifndef BOOTLOADER_H
#define BOOTLOADER_H

#include "robus_struct.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
typedef enum
{
    BOOT_MODE,
    JUMP_TO_APP_MODE,
    APP_RELOAD_MODE,
} bootloader_mode_t;

#define BOOTLOADER_RCV_COMMAND   0x01
#define BOOTLOADER_SND_COMMAND   0x10
#define BOOTLOADER_ERROR_COMMAND 0x20
typedef enum
{
    BOOTLOADER_IDLE,
    BOOTLOADER_START = BOOTLOADER_RCV_COMMAND,
    BOOTLOADER_STOP,
    BOOTLOADER_READY,
    BOOTLOADER_ERASE,
    BOOTLOADER_BIN_CHUNK,
    BOOTLOADER_BIN_END,
    BOOTLOADER_CRC_TEST,
    BOOTLOADER_APP_SAVED,
    BOOTLOADER_RESET,
    BOOTLOADER_READY_RESP = BOOTLOADER_SND_COMMAND,
    BOOTLOADER_BIN_HEADER_RESP,
    BOOTLOADER_ERASE_RESP,
    BOOTLOADER_BIN_CHUNK_RESP,
    BOOTLOADER_BIN_END_RESP,
    BOOTLOADER_CRC_RESP,
    BOOTLOADER_ERROR_SIZE = BOOTLOADER_ERROR_COMMAND,
} bootloader_cmd_t;

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Function
 ******************************************************************************/

/******************************************************************************
 * @brief Initialize bootloader function
 ******************************************************************************/
void LuosBootloader_Init(void);

/******************************************************************************
 * @brief Main function used by the bootloader app
 ******************************************************************************/
void LuosBootloader_Loop(void);

/******************************************************************************
 * @brief function used by Luos to send message to the bootloader
 ******************************************************************************/
void LuosBootloader_MsgHandler(msg_t *);
#ifndef BOOTLOADER
void LuosBootloader_JumpToBootloader(void);
#endif

#endif /* BOOTLOADER_H */