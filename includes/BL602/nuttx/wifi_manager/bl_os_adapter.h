/****************************************************************************
 * <includes/BL602/nuttx/bl_private/bl_os_adapter.h>
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef _BL_OS_ADAPTER_H_
#define _BL_OS_ADAPTER_H_

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BL_OS_ADAPTER_VERSION  ((int)0x00000001)


typedef struct {
    int _version;
    void (*_printf)(const char *fmt, ...);
    int (*_init)(void);
    uint32_t (*_enter_critical)(void);
    void (*_exit_critical)(uint32_t level);
    int (*_msleep)(long ms);
    int (*_sleep)(unsigned int seconds);
    int (*_event_notify)(int evt, int val);
    void (*_lock_giant)(void);
    void (*_unlock_gaint)(void);
    void (*_irq_attach)(int32_t n, void *f, void *arg);
    int (*_workqueue_submit)(void *woker, void *argv, long tick);
    void *(*_timer_create)(void *func, void *argv);
    int (*_timer_delete)(void *timerid);
    int (*_timer_start_once)(void *timerid, long t_sec, long t_nsec);
    int (*_timer_start_periodic)(void *timerid, long t_sec, long t_nsec);
    void *(*_sem_create)(uint32_t init);
    void (*_sem_delete)(void *semphr);
    int32_t (*_sem_take)(void *semphr, uint32_t tick);
    int32_t (*_sem_give)(void *semphr);
    void *(*_mutex_create)(void);
    void (*_mutex_delete)(void *mutex);
    int32_t (*_mutex_lock)(void *mutex);
    int32_t (*_mutex_unlock)(void *mutex);
    void *(* _queue_create)(uint32_t queue_len, uint32_t item_size);
    void (* _queue_delete)(void *queue);
    int32_t (* _queue_send)(void *queue, void *item, size_t len, uint32_t block_time_tick);
    int (* _queue_recv)(void *queue, void *item, uint32_t tick);
    void *(* _malloc)(unsigned int size);
    void (* _free)(void *p);
    void *(*_zalloc)(unsigned int size);
    uint64_t (* _get_time_ms)(void);
} bl_ops_funcs_t;

extern bl_ops_funcs_t g_bl_ops_funcs;


#ifdef __cplusplus
}
#endif

#endif /* _BL_OS_ADAPTER_H_ */