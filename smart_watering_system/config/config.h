#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>
#include <stdio.h>

// Các trạng thái hoạt động (Requirement 1)
typedef enum { MODE_AUTO, MODE_MANUAL } SystemMode_t;
typedef enum { PUMP_OFF, PUMP_ON } PumpStatus_t;
typedef enum { LED_GREEN, LED_YELLOW, LED_RED } LedState_t;

// Cấu trúc dữ liệu cảm biến (Requirement 2)
typedef struct {
    float soilMoisture;
    float temperature;
} SensorData_t;

// Cấu trúc lưu trữ cài đặt
typedef struct {
    float minMoistureThreshold;
    float maxMoistureThreshold;
    uint32_t maxWateringDuration_s;
    uint32_t sensorReadInterval_s;
    uint32_t manualWateringDuration_s;
} SystemSettings_t;

// Quản lý trạng thái hệ thống
typedef struct {
    SystemMode_t mode;
    PumpStatus_t pumpStatus;
    LedState_t ledStatus;
    uint32_t wateringTimer;
} SystemState_t;

#endif