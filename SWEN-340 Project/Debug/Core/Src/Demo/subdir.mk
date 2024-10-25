################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Demo/adc_dac_demo.c \
../Core/Src/Demo/demo.c 

OBJS += \
./Core/Src/Demo/adc_dac_demo.o \
./Core/Src/Demo/demo.o 

C_DEPS += \
./Core/Src/Demo/adc_dac_demo.d \
./Core/Src/Demo/demo.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Demo/%.o Core/Src/Demo/%.su Core/Src/Demo/%.cyclo: ../Core/Src/Demo/%.c Core/Src/Demo/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I"C:/Users/raymo/OneDrive/Documents/GitHub/340-repo-Yardomn/SWEN-340 Project/Core/Inc/Demo" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/raymo/OneDrive/Documents/GitHub/340-repo-Yardomn/SWEN-340 Project/Core/Inc/Devices" -I"C:/Users/raymo/OneDrive/Documents/GitHub/340-repo-Yardomn/SWEN-340 Project/Core/Inc/HW" -I"C:/Users/raymo/OneDrive/Documents/GitHub/340-repo-Yardomn/SWEN-340 Project/Core/Inc/Project" -I"C:/Users/raymo/OneDrive/Documents/GitHub/340-repo-Yardomn/SWEN-340 Project/Core/Inc/System" -I../Drivers/CMSIS/Include -I"C:/Users/raymo/OneDrive/Documents/GitHub/340-repo-Yardomn/SWEN-340 Project/Core/Inc/Activities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Demo

clean-Core-2f-Src-2f-Demo:
	-$(RM) ./Core/Src/Demo/adc_dac_demo.cyclo ./Core/Src/Demo/adc_dac_demo.d ./Core/Src/Demo/adc_dac_demo.o ./Core/Src/Demo/adc_dac_demo.su ./Core/Src/Demo/demo.cyclo ./Core/Src/Demo/demo.d ./Core/Src/Demo/demo.o ./Core/Src/Demo/demo.su

.PHONY: clean-Core-2f-Src-2f-Demo

