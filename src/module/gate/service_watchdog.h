/*
 * service_watchdog.h
 *
 *  Created on: May 20, 2017
 *      Author: ltzd
 */

#ifndef MODULE_GATE_SERVICE_WATCHDOG_H_
#define MODULE_GATE_SERVICE_WATCHDOG_H_

#include "skynet.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

struct watchdog {

};

static struct watchdog *
watchdog_create(void) {
	puts("watchdog create ==");
	struct watchdog * inst = skynet_malloc(sizeof(*inst));

	return inst;
}

static void
watchdog_release(struct watchdog * inst) {

}

static void
watchdog_filter_args(struct skynet_context * context, int type, int *session, void ** data, size_t * sz) {
	int needcopy = !(type & PTYPE_TAG_DONTCOPY);
	int allocsession = type & PTYPE_TAG_ALLOCSESSION;
	type &= 0xff;

	if (allocsession) {
		assert(*session == 0);
		*session = skynet_context_newsession(context);
	}

	if (needcopy && *data) {
		char * msg = skynet_malloc(*sz+1);
		memcpy(msg, *data, *sz);
		msg[*sz] = '\0';
		*data = msg;
	}

	*sz |= (size_t)type << MESSAGE_TYPE_SHIFT;
}

static static int
watchdog_cb(struct watchdog * context, void *ud, int type, int session, uint32_t source, const void * msg, size_t sz) {
//	int tmpSession = 0;
//	watchdog_filter_args(context, type, &tmpSession, (void **)&msg, &sz);
	char * mymsg = (char*)msg;
	int i;
	for (i=0;i<sz;i++) {
		if (mymsg[i]==' ') {
			break;
		}
	}
	int fd = strtol(mymsg , NULL, 10);
	printf("find the fd =%d \n",fd);

	if (memcmp(mymsg+i+1,"open",4)==0) {
		int k;
		for (k=i+1+4+1;k<sz;k++) {
			if (mymsg[k]==' ') {
				break;
			}
		}
		char addr[32] = {0};
		memcpy(addr,mymsg+k+1,sz-k-1-2);
		printf("addr == %s \n",addr);
	}else if(memcmp(mymsg+i+1,"data",4)==0)
	{
		char * data = mymsg+i+4+1+1;
		int datalen = sz-i-4-1-1;
		char addr[32] = {0};
		memcpy(addr,mymsg+i+4+1+1,sz-i-4-1-1);
		printf("data ==%s,len=%d \n",addr,datalen);
	}
	printf("watchdog_cb = %d , session=%d,source=%d,msg=%s,sz=%d\n",type,session,source,msg,sz);
	struct watchdog * inst = ud;
	switch (type) {
	case PTYPE_SOCKET:

		break;
	}

	return 0;
}

static int
watchdog_init(struct watchdog * inst, struct skynet_context *ctx, const char * parm) {
	skynet_callback(ctx, inst, watchdog_cb);
	skynet_command(ctx, "REG", ".watchdog");
	return 0;
}



#endif /* MODULE_GATE_SERVICE_WATCHDOG_H_ */
