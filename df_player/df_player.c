/*
 * df_player.c
 *
 *  Created on: Sep 7, 2021
 *      Author: Miguel Murillo
 */
#include <df_player.h>
/*
 * Serial Communication specifications:
 * Support for asynchronous serial communication mode via PC serial sending commands
 * Communication Standard:9600 bps
 * Data bits : 1
 * Checkout : none
 * Flow Control : none
 */

void df_sendCMD(uint8_t cmd, uint16_t parameter){
	uint16_t checksum = 0;
	cmdFormat[0] = start_Byte;
	cmdFormat[1] = version;
	cmdFormat[2] = cmd_Len;
	cmdFormat[3] = cmd;
	cmdFormat[4] = acknowledge;
	cmdFormat[5] = (parameter & 0xFF00) >> 8;
	cmdFormat[6] = parameter & 0xFF;
	checksum = 0 - (version+cmd_Len+cmd+acknowledge+cmdFormat[5]+cmdFormat[6]);
	cmdFormat[7] = (checksum & 0xFF00) >> 8;
	cmdFormat[8] = checksum & 0xFF;
	cmdFormat[9] = end_Byte;

	HAL_UART_Transmit(&huart4, cmdFormat, cmd_Len+4, 100);
}

void df_initPlayer(void){
	df_sendCMD(innit, tf);
	HAL_Delay(200);
}

void df_setVolume(uint8_t v){
	df_sendCMD(specify_volume, v);
}

void df_next (void){
	df_sendCMD(next, 0);
	HAL_Delay(200);
}

void df_previous(void){
	df_sendCMD(previous, 0);
	HAL_Delay(200);
}

void df_pause (void){
	df_sendCMD(pause, 0);
	HAL_Delay(200);
}

