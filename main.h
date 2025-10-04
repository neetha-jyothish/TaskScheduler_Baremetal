/*
 * main.h
 *
 *  Created on: Sep 14, 2025
 *      Author: Neetha Jyothish
 */

#ifndef MAIN_H_
#define MAIN_H_
//							0x01000000U
#define DUMMY_XPSR			(0x01000000U)
#define MAX_TASKS			(5)
#define SRAM_START			(0x20000000)
#define SRAM_SIZE			((128) * (1024))
#define SRAM_END			((SRAM_START) + (SRAM_SIZE))

#define TASK_STACK_SIZE		(1024)
#define SCHED_STACK_SIZE	(1024)

#define T1_STACK_START			(SRAM_END)
#define T2_STACK_START			((T1_STACK_START) - (1 * TASK_STACK_SIZE))
#define T3_STACK_START			((T1_STACK_START) - (2 * TASK_STACK_SIZE))
#define T4_STACK_START			((T1_STACK_START) - (3 * TASK_STACK_SIZE))
#define SCHED_STACK_START		((T1_STACK_START) - (4 * TASK_STACK_SIZE))
#define IDLE_TASK_STACK_START	((T1_STACK_START) - (5 * TASK_STACK_SIZE))

#define TICK_HZ				(1000)
#define HSI_CLK				(16000000U)
#define SYSTICK_TIM_CLK		(HSI_CLK)

#define TASK_READY_STATE	(0x00)
#define TASK_BLOCKED_STATE	(0xFF)


#define INTERRUPT_DISABLE() do{ __asm volatile("MOV R0, #0x01"); __asm volatile("MSR PRIMASK, R0");}while(0)
#define INTERRUPT_ENABLE() do{ __asm volatile("MOV R0, #0x00"); __asm volatile("MSR PRIMASK, R0");}while(0)
#endif /* MAIN_H_ */
