################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Cliente.c \
../src/Informe.c \
../src/Parcial.c \
../src/Publicacion.c \
../src/utn.c 

OBJS += \
./src/Cliente.o \
./src/Informe.o \
./src/Parcial.o \
./src/Publicacion.o \
./src/utn.o 

C_DEPS += \
./src/Cliente.d \
./src/Informe.d \
./src/Parcial.d \
./src/Publicacion.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


