#include "hal_actuators.h"
#include <stdio.h>

void HAL_TurnPumpOn(SystemState_t *s) {
    if (s == NULL) return;
    
    s->pumpStatus = PUMP_ON;
    s->ledStatus = LED_YELLOW;
    printf("[HAL] Output: Pump ACTIVATED | LED: YELLOW\n");
}

void HAL_TurnPumpOff(SystemState_t *s) {
    if (s == NULL) return;

    s->pumpStatus = PUMP_OFF;
    s->ledStatus = LED_GREEN;
    printf("[HAL] Output: Pump DEACTIVATED | LED: GREEN\n");
}