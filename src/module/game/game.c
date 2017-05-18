/*
 * game.c
 *
 *  Created on: Aug 17, 2016
 *      Author: ltzd
 */

#include <stdio.h>

void * game_create(){
	printf("game_create==");
}

int game_init(void * inst,const char * parm) {
	printf("game_init==");
	return 0;
}

void game_release(void * inst) {
	printf("game_release==");
}

void game_signal(void * inst, int signal) {
	printf("game_signal==");
}
