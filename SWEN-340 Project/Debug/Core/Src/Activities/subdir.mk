################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Activities/activity13.c \
../Core/Src/Activities/activity8.c 

OBJS += \
./Core/Src/Activities/activity13.o \
./Core/Src/Activities/activity8.o 

C_DEPS += \
./Core/Src/Activities/activity13.d \
./Core/Src/Activities/activity8.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Activities/%.o Core/Src/Activities/%.su Core/Src/Activities/%.cyclo: ../Core/Src/Activities/%.c Core/Src/Activities/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I"C:/Users/raymo/OneDrive/Documents/GitHub/340-repo-Yardomn/SWEN-340 Project/Core/Inc/Demo" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/raymo/OneDrive/Documents/GitHub/340-repo-Yardomn/SWEN-340 Project/Core/Inc/Devices" -I"C:/Users/raymo/OneDrive/Documents/GitHub/340-repo-Yardomn/SWEN-340 Project/Core/Inc/HW" -I"C:/Users/raymo/OneDrive/Documents/GitHub/340-repo-Yardomn/SWEN-340 Project/Core/Inc/Project" -I"C:/Users/raymo/OneDrive/Documents/GitHub/340-repo-Yardomn/SWEN-340 Project/Core/Inc/System" -I../Drivers/CMSIS/Include -I"C:/Users/raymo/OneDrive/Documents/GitHub/340-repo-Yardomn/SWEN-340 Project/Core/Inc/Activities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Activities

clean-Core-2f-Src-2f-Activities:
	-$(RM) ./Core/Src/Activities/activity13.cyclo ./Core/Src/Activities/activity13.d ./Core/Src/Activities/activity13.o ./Core/Src/Activities/activity13.su ./Core/Src/Activities/activity8.cyclo ./Core/Src/Activities/activity8.d ./Core/Src/Activities/activity8.o ./Core/Src/Activities/activity8.su

.PHONY: clean-Core-2f-Src-2f-Activities

