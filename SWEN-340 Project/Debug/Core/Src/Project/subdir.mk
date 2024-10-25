################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Project/S1_button_handler.c \
../Core/Src/Project/USARTinterrupt.c \
../Core/Src/Project/endian_converter.c \
../Core/Src/Project/local_button_handler.c \
../Core/Src/Project/midi_header.c \
../Core/Src/Project/play_song.c \
../Core/Src/Project/printf.c \
../Core/Src/Project/project.c \
../Core/Src/Project/song.c \
../Core/Src/Project/systick_handler.c \
../Core/Src/Project/tone.c 

OBJS += \
./Core/Src/Project/S1_button_handler.o \
./Core/Src/Project/USARTinterrupt.o \
./Core/Src/Project/endian_converter.o \
./Core/Src/Project/local_button_handler.o \
./Core/Src/Project/midi_header.o \
./Core/Src/Project/play_song.o \
./Core/Src/Project/printf.o \
./Core/Src/Project/project.o \
./Core/Src/Project/song.o \
./Core/Src/Project/systick_handler.o \
./Core/Src/Project/tone.o 

C_DEPS += \
./Core/Src/Project/S1_button_handler.d \
./Core/Src/Project/USARTinterrupt.d \
./Core/Src/Project/endian_converter.d \
./Core/Src/Project/local_button_handler.d \
./Core/Src/Project/midi_header.d \
./Core/Src/Project/play_song.d \
./Core/Src/Project/printf.d \
./Core/Src/Project/project.d \
./Core/Src/Project/song.d \
./Core/Src/Project/systick_handler.d \
./Core/Src/Project/tone.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Project/%.o Core/Src/Project/%.su Core/Src/Project/%.cyclo: ../Core/Src/Project/%.c Core/Src/Project/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I"C:/Users/raymo/OneDrive/Documents/GitHub/340-repo-Yardomn/SWEN-340 Project/Core/Inc/Demo" -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I"C:/Users/raymo/OneDrive/Documents/GitHub/340-repo-Yardomn/SWEN-340 Project/Core/Inc/Devices" -I"C:/Users/raymo/OneDrive/Documents/GitHub/340-repo-Yardomn/SWEN-340 Project/Core/Inc/HW" -I"C:/Users/raymo/OneDrive/Documents/GitHub/340-repo-Yardomn/SWEN-340 Project/Core/Inc/Project" -I"C:/Users/raymo/OneDrive/Documents/GitHub/340-repo-Yardomn/SWEN-340 Project/Core/Inc/System" -I../Drivers/CMSIS/Include -I"C:/Users/raymo/OneDrive/Documents/GitHub/340-repo-Yardomn/SWEN-340 Project/Core/Inc/Activities" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Project

clean-Core-2f-Src-2f-Project:
	-$(RM) ./Core/Src/Project/S1_button_handler.cyclo ./Core/Src/Project/S1_button_handler.d ./Core/Src/Project/S1_button_handler.o ./Core/Src/Project/S1_button_handler.su ./Core/Src/Project/USARTinterrupt.cyclo ./Core/Src/Project/USARTinterrupt.d ./Core/Src/Project/USARTinterrupt.o ./Core/Src/Project/USARTinterrupt.su ./Core/Src/Project/endian_converter.cyclo ./Core/Src/Project/endian_converter.d ./Core/Src/Project/endian_converter.o ./Core/Src/Project/endian_converter.su ./Core/Src/Project/local_button_handler.cyclo ./Core/Src/Project/local_button_handler.d ./Core/Src/Project/local_button_handler.o ./Core/Src/Project/local_button_handler.su ./Core/Src/Project/midi_header.cyclo ./Core/Src/Project/midi_header.d ./Core/Src/Project/midi_header.o ./Core/Src/Project/midi_header.su ./Core/Src/Project/play_song.cyclo ./Core/Src/Project/play_song.d ./Core/Src/Project/play_song.o ./Core/Src/Project/play_song.su ./Core/Src/Project/printf.cyclo ./Core/Src/Project/printf.d ./Core/Src/Project/printf.o ./Core/Src/Project/printf.su ./Core/Src/Project/project.cyclo ./Core/Src/Project/project.d ./Core/Src/Project/project.o ./Core/Src/Project/project.su ./Core/Src/Project/song.cyclo ./Core/Src/Project/song.d ./Core/Src/Project/song.o ./Core/Src/Project/song.su ./Core/Src/Project/systick_handler.cyclo ./Core/Src/Project/systick_handler.d ./Core/Src/Project/systick_handler.o ./Core/Src/Project/systick_handler.su ./Core/Src/Project/tone.cyclo ./Core/Src/Project/tone.d ./Core/Src/Project/tone.o ./Core/Src/Project/tone.su

.PHONY: clean-Core-2f-Src-2f-Project

