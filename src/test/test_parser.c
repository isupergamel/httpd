/* Copyright 1999-2006 The Apache Software Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* This program tests the ap_get_list_item routine in ../main/util.c.
 *
 * The defines in this sample compile line are specific to Roy's system.
 * They should match whatever was used to compile Apache first.
 *
     gcc -g -O2 -I../os/unix -I../include -o test_parser \
            -DSOLARIS2=250 -Wall -DALLOC_DEBUG -DPOOL_DEBUG \
            ../main/alloc.o ../main/buff.o ../main/util.o \
            ../ap/libap.a -lsocket -lnsl test_parser.c
 * 
 * Roy Fielding, 1999
 */
#include <stdio.h>
#include <stdlib.h>
#include "httpd.h"
#include "ap_alloc.h"

/*
 * Dummy a bunch of stuff just to get a compile
 */
uid_t ap_user_id;
gid_t ap_group_id;
void *ap_dummy_mutex = &ap_dummy_mutex;
char *ap_server_argv0;

API_EXPORT(void) ap_block_alarms(void)
{
    ;
}

API_EXPORT(void) ap_unblock_alarms(void)
{
    ;
}

API_EXPORT(void) ap_log_error(const char *file, int line, int level,
                               const request_rec *r, const char *fmt, ...)
{
    ;
}

int main (void)
{
    ap_pool *p;
    const char *field;
    char *newstr;
    char instr[512];

    p = ap_init_alloc();

    while (gets(instr)) {
        printf("  [%s] ==\n", instr);
        field = instr;
        while ((newstr = ap_get_list_item(p, &field)) != NULL)
            printf("  <%s> ..\n", newstr);
    }
    
    exit(0);
}
