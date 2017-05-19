################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/skynet-src/malloc_hook.c \
../src/skynet-src/skynet_daemon.c \
../src/skynet-src/skynet_error.c \
../src/skynet-src/skynet_handle.c \
../src/skynet-src/skynet_harbor.c \
../src/skynet-src/skynet_log.c \
../src/skynet-src/skynet_module.c \
../src/skynet-src/skynet_monitor.c \
../src/skynet-src/skynet_mq.c \
../src/skynet-src/skynet_server.c \
../src/skynet-src/skynet_socket.c \
../src/skynet-src/skynet_start.c \
../src/skynet-src/skynet_timer.c \
../src/skynet-src/socket_server.c 

OBJS += \
./src/skynet-src/malloc_hook.o \
./src/skynet-src/skynet_daemon.o \
./src/skynet-src/skynet_error.o \
./src/skynet-src/skynet_handle.o \
./src/skynet-src/skynet_harbor.o \
./src/skynet-src/skynet_log.o \
./src/skynet-src/skynet_module.o \
./src/skynet-src/skynet_monitor.o \
./src/skynet-src/skynet_mq.o \
./src/skynet-src/skynet_server.o \
./src/skynet-src/skynet_socket.o \
./src/skynet-src/skynet_start.o \
./src/skynet-src/skynet_timer.o \
./src/skynet-src/socket_server.o 

C_DEPS += \
./src/skynet-src/malloc_hook.d \
./src/skynet-src/skynet_daemon.d \
./src/skynet-src/skynet_error.d \
./src/skynet-src/skynet_handle.d \
./src/skynet-src/skynet_harbor.d \
./src/skynet-src/skynet_log.d \
./src/skynet-src/skynet_module.d \
./src/skynet-src/skynet_monitor.d \
./src/skynet-src/skynet_mq.d \
./src/skynet-src/skynet_server.d \
./src/skynet-src/skynet_socket.d \
./src/skynet-src/skynet_start.d \
./src/skynet-src/skynet_timer.d \
./src/skynet-src/socket_server.d 


# Each subdirectory must supply rules for building sources it contributes
src/skynet-src/%.o: ../src/skynet-src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -DNOUSE_JEMALLOC -I"/Users/ltzd/Documents/workspacecpp/cskynet/src/module/logger" -I"/Users/ltzd/Documents/workspacecpp/cskynet/src/module/gate" -I"/Users/ltzd/Documents/workspacecpp/cskynet/src/module/game" -I"/Users/ltzd/Documents/workspacecpp/cskynet/include" -I"/Users/ltzd/Documents/workspacecpp/cskynet/src/module" -I"/Users/ltzd/Documents/workspacecpp/cskynet/src/skynet-src" -I"/Users/ltzd/Documents/workspacecpp/cskynet/src/service-src" -O0 -g3 -Wall -c -fmessage-length=0 -m64 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


