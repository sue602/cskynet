/*
 ============================================================================
 Name        : cskynet.c
 Author      : vincent
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "skynet_imp.h"



int
sigign() {
	struct sigaction sa;
	sa.sa_handler = SIG_IGN;
	sigaction(SIGPIPE, &sa, 0);
	return 0;
}

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	skynet_globalinit();

	sigign();

	struct skynet_config config;
	config.thread = 8;
	config.module_path = "./?.so";
	config.harbor = 1;
	config.bootstrap = "snlua bootstrap";
	config.daemon = NULL;
	config.logger = NULL;
	config.logservice = "logger";
	config.profile = 1;

	skynet_start(&config);
	skynet_globalexit();

	puts("!!!Hello World!!! end"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
