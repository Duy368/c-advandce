#include "spws_controller.h"
#include <stdio.h>

void SPWS_ProcessAutoMode(SystemState_t *state, SystemSettings_t *settings, SensorData_t *sensors) {
    if (state->currentMode != MODE_AUTO) return;

    // Logic: Nếu quá khô -> Bật bơm
    if (sensors->currentMoisture < settings->minMoistureThreshold) {
        if (state->pumpStatus == PUMP_OFF) {
            state->pumpStatus = PUMP_ON;
            state->ledStatus = LED_WATERING;
            printf("[AUTO] Low moisture detected: %.2f%%. Pump ON.\n", sensors->currentMoisture);
        }
    } 
    // Logic: Tắt bơm khi đủ độ ẩm hoặc quá thời gian
    else if (sensors->currentMoisture > settings->maxMoistureThreshold || 
             state->wateringTimeCounter >= settings->maxWateringDuration_s) {
        if (state->pumpStatus == PUMP_ON) {
            state->pumpStatus = PUMP_OFF;
            state->ledStatus = LED_NORMAL;
            printf("[AUTO] Condition met. Pump OFF.\n");
        }
    }
}