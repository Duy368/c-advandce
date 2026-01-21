#ifndef HAL_ACTUATORS_H
#define HAL_ACTUATORS_H

#include "config.h"

/**
 * @brief Activates the water pump and updates system status.
 * @param s Pointer to the system state structure.
 */
void HAL_TurnPumpOn(SystemState_t *s);

/**
 * @brief Deactivates the water pump and updates system status.
 * @param s Pointer to the system state structure.
 */
void HAL_TurnPumpOff(SystemState_t *s);

#endif