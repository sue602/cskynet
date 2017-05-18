################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/module/logger/service_logger.c 

OBJS += \
./src/module/logger/service_logger.o 

C_DEPS += \
./src/module/logger/service_logger.d 


# Each subdirectory must supply rules for building sources it contributes
src/module/logger/%.o: ../src/module/logger/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -DNOUSE_JEMALLOC -I"/Users/ltzd/Documents/workspacecpp/cskynet/src/module/logger" -I"/Users/ltzd/Documents/workspacecpp/cskynet/src/module/game" -I"/Users/ltzd/Documents/workspacecpp/cskynet/include" -I"/Users/ltzd/Documents/workspacecpp/cskynet/src/module" -I"/Users/ltzd/Documents/workspacecpp/cskynet/src/skynet-src" -I"/Users/ltzd/Documents/workspacecpp/cskynet/src/service-src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


