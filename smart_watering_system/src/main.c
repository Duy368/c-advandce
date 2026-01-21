#include "config.h"
#include "spws_controller.h"
#include <unistd.h>

int main() {
    // 1. Khởi tạo mặc định
    SystemSettings_t config = {30.0, 70.0, 15, 2, 10};
    SystemState_t spws = {MODE_AUTO, PUMP_OFF, LED_NORMAL, 0};
    SensorData_t currentData = {25.0, 28.5}; // Giá trị giả lập

    printf("--- System Smart Plant Watering Initialized ---\n");

    // 2. Vòng lặp chính
    while (1) {
        // Mô phỏng đọc cảm biến
        SPWS_ProcessAutoMode(&spws, &config, &currentData);
        
        // Mô phỏng tăng độ ẩm nếu đang tưới
        if (spws.pumpStatus == PUMP_ON) {
            currentData.currentMoisture += 10.0;
            spws.wateringTimeCounter++;
        } else {
            currentData.currentMoisture -= 2.0;
            spws.wateringTimeCounter = 0;
        }

        sleep(1); // Giả lập chu kỳ 1 giây
        if (currentData.currentMoisture > 100.0) break; // Thoát giả lập
    }
    return 0;
}