/**
 * @author  Nickel_Liang <nickelliang>
 * @date    2018-04-21
 * @file    task_referee.h
 * @brief   RTOS task fro referee tx and rx
 * @log     2018-04-21 nickelliang
 */

#include "cmsis_os.h"
#include "referee.h"

/* Referee signal handling */
#define REFEREE_RX_SIGNAL   (1 << 0)
#define REFEREE_TX_SIGNAL   (1 << 1)

/* Global variable */
extern referee_t    referee_info;
extern osThreadId   referee_task_handle;

/**
 * Create referee task
 *
 * @author Nickel_Liang
 * @date   2018-04-21
 */
void referee_task_create(void);

/**
 * Initialize referee task software and hardware
 *
 * @return            [description]
 * @author Nickel_Liang
 * @date   2018-04-21
 */
uint8_t referee_task_init(void);

/**
 * Referee data processing task
 *
 * @param  argu       Passed in argument. Usually not used
 * @author Nickel_Liang
 * @date   2018-04-21
 */
void referee_task(void const *argu);