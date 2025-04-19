GPS Data Logger using STM32 (DMA + UART)
This project demonstrates real-time GPS data acquisition using an STM32F4 series microcontroller. The system is designed to receive data from a GPS module (like NEO-6M) via USART1 using DMA, and transmit the received data to a serial terminal through USART2 for debugging or logging purposes.

🧠 Key Features:
📡 GPS Module Interface (NEO-6M) via UART

🔁 DMA-based UART Reception for efficient, non-blocking GPS data handling

🖥️ Real-time Data Output to a serial terminal using USART2

🧰 Modular Codebase with separation into:

gps.c/.h – GPS data handling

usart.c/.h – Debug output through UART

main.c/.h – System configuration and main loop

🧱 Architecture:
USART1 (with DMA) → GPS input

USART2 → Serial monitor output (for debug/logging)

HAL_UART_RxCpltCallback() → Interrupt for DMA reception completion

printf() redirected to USART2 for easier debugging

📦 Requirements:
STM32F4 MCU (e.g., Nucleo-F446RE)

NEO-6M GPS module

STM32CubeMX & STM32CubeIDE

USB-to-Serial or onboard ST-LINK for serial monitoring

💡 Use Case:
This setup is ideal for:

Rocketry or drone telemetry

GPS-based location tracking

Embedded systems learning (DMA + UART + Interrupts)
