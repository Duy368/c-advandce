#ifndef HAL_SENSORS_H
#define HAL_SENSORS_H

/**
 * @brief Reads the current soil moisture level.
 * @return float Moisture percentage (0.0 - 100.0).
 */
float HAL_ReadSoilMoisture(void);

/**
 * @brief Reads the ambient temperature.
 * @return float Temperature in Celsius.
 */
float HAL_ReadTemperature(void);

#endif