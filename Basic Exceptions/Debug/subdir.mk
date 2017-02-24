################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Basic\ Exceptions.cpp 

OBJS += \
./Basic\ Exceptions.o 

CPP_DEPS += \
./Basic\ Exceptions.d 


# Each subdirectory must supply rules for building sources it contributes
Basic\ Exceptions.o: ../Basic\ Exceptions.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"Basic Exceptions.d" -MT"Basic\ Exceptions.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


