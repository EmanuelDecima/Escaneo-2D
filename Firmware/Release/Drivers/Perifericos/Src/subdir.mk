################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Perifericos/Src/button_handler.c \
../Drivers/Perifericos/Src/clock_config.c \
../Drivers/Perifericos/Src/delay.c \
../Drivers/Perifericos/Src/fonts.c \
../Drivers/Perifericos/Src/gpio.c \
../Drivers/Perifericos/Src/i2c.c \
../Drivers/Perifericos/Src/mef.c \
../Drivers/Perifericos/Src/menu.c \
../Drivers/Perifericos/Src/motorpap.c \
../Drivers/Perifericos/Src/ssd1306_oled.c 

OBJS += \
./Drivers/Perifericos/Src/button_handler.o \
./Drivers/Perifericos/Src/clock_config.o \
./Drivers/Perifericos/Src/delay.o \
./Drivers/Perifericos/Src/fonts.o \
./Drivers/Perifericos/Src/gpio.o \
./Drivers/Perifericos/Src/i2c.o \
./Drivers/Perifericos/Src/mef.o \
./Drivers/Perifericos/Src/menu.o \
./Drivers/Perifericos/Src/motorpap.o \
./Drivers/Perifericos/Src/ssd1306_oled.o 

C_DEPS += \
./Drivers/Perifericos/Src/button_handler.d \
./Drivers/Perifericos/Src/clock_config.d \
./Drivers/Perifericos/Src/delay.d \
./Drivers/Perifericos/Src/fonts.d \
./Drivers/Perifericos/Src/gpio.d \
./Drivers/Perifericos/Src/i2c.d \
./Drivers/Perifericos/Src/mef.d \
./Drivers/Perifericos/Src/menu.d \
./Drivers/Perifericos/Src/motorpap.d \
./Drivers/Perifericos/Src/ssd1306_oled.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Perifericos/Src/%.o Drivers/Perifericos/Src/%.su Drivers/Perifericos/Src/%.cyclo: ../Drivers/Perifericos/Src/%.c Drivers/Perifericos/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Estudiante.DESKTOP-5OVK98J/Desktop/Escaneo-2D/Escaneo-2D/Firmware/Drivers/Perifericos" -I"C:/Users/Estudiante.DESKTOP-5OVK98J/Desktop/Escaneo-2D/Escaneo-2D/Firmware/Drivers/Perifericos/Inc" -I"C:/Users/Estudiante.DESKTOP-5OVK98J/Desktop/Escaneo-2D/Escaneo-2D/Firmware/Drivers/Perifericos/Src" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Perifericos-2f-Src

clean-Drivers-2f-Perifericos-2f-Src:
	-$(RM) ./Drivers/Perifericos/Src/button_handler.cyclo ./Drivers/Perifericos/Src/button_handler.d ./Drivers/Perifericos/Src/button_handler.o ./Drivers/Perifericos/Src/button_handler.su ./Drivers/Perifericos/Src/clock_config.cyclo ./Drivers/Perifericos/Src/clock_config.d ./Drivers/Perifericos/Src/clock_config.o ./Drivers/Perifericos/Src/clock_config.su ./Drivers/Perifericos/Src/delay.cyclo ./Drivers/Perifericos/Src/delay.d ./Drivers/Perifericos/Src/delay.o ./Drivers/Perifericos/Src/delay.su ./Drivers/Perifericos/Src/fonts.cyclo ./Drivers/Perifericos/Src/fonts.d ./Drivers/Perifericos/Src/fonts.o ./Drivers/Perifericos/Src/fonts.su ./Drivers/Perifericos/Src/gpio.cyclo ./Drivers/Perifericos/Src/gpio.d ./Drivers/Perifericos/Src/gpio.o ./Drivers/Perifericos/Src/gpio.su ./Drivers/Perifericos/Src/i2c.cyclo ./Drivers/Perifericos/Src/i2c.d ./Drivers/Perifericos/Src/i2c.o ./Drivers/Perifericos/Src/i2c.su ./Drivers/Perifericos/Src/mef.cyclo ./Drivers/Perifericos/Src/mef.d ./Drivers/Perifericos/Src/mef.o ./Drivers/Perifericos/Src/mef.su ./Drivers/Perifericos/Src/menu.cyclo ./Drivers/Perifericos/Src/menu.d ./Drivers/Perifericos/Src/menu.o ./Drivers/Perifericos/Src/menu.su ./Drivers/Perifericos/Src/motorpap.cyclo ./Drivers/Perifericos/Src/motorpap.d ./Drivers/Perifericos/Src/motorpap.o ./Drivers/Perifericos/Src/motorpap.su ./Drivers/Perifericos/Src/ssd1306_oled.cyclo ./Drivers/Perifericos/Src/ssd1306_oled.d ./Drivers/Perifericos/Src/ssd1306_oled.o ./Drivers/Perifericos/Src/ssd1306_oled.su

.PHONY: clean-Drivers-2f-Perifericos-2f-Src

