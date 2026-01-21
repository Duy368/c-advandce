#ifndef SPWS_CONTROLLER_H
#define SPWS_CONTROLLER_H

#include "../config.h"
#include <stdio.h>

/**
 * @brief Process logic for Automatic Mode based on sensor thresholds.
 * @param dev Pointer to the system control structure.
 */
void SPWS_ProcessAutoMode(SPWS_Control_t *dev);

#endif