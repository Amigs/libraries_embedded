/*
 * df_player.h
 *
 *  Created on: Sep 7, 2021
 *      Author: Miguel Murillo
 */

#ifndef INC_DF_PLAYER_H_
#define INC_DF_PLAYER_H_

#include "stm32f4xx_hal.h"
#include "main.h"
#include "stdio.h"

# define start_Byte  0x7E
# define end_Byte    0xEF
# define version     0xFF
# define cmd_Len     0x06
# define acknowledge 0x01

enum direct_cmd{
	next=0x01,previous,specify_tracking,increase_volume,decrease_volume,specify_volume,pause=0x0E, innit=0x3F
};

enum onlineDevices{
	u_disk=1,tf,disk_tf,pc,flash=8
};

void df_sendCMD(uint8_t cmd, uint16_t parameter);
void df_setVolume(uint8_t v);
void df_initPlayer(void);
void df_next (void);
void df_pause (void);
void df_previous(void);

UART_HandleTypeDef huart4;
uint8_t cmdFormat[10] = {};

#endif /* INC_DF_PLAYER_H_ */
