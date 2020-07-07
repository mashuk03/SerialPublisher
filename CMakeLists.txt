cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
set(CMAKE_CXX_STANDARD 14)
set(PROJECT_NAME SerialPublisher)

set(${PROJECT_NAME}_BOARD mega)
set(ARDUINO_CPU atmega2560)
project(${PROJECT_NAME})

# Define additional source and header files or default arduino sketch files
set(${PROJECT_NAME}_SRCS
        serial_publisher.cpp
        serial_publisher_test.cpp
        ThirdParty/Timer-2.1/Event.cpp
        ThirdParty/Timer-2.1/Timer.cpp
        ReadStringSerial.cpp
        FunctionGenerator.cpp
        )
set(${PROJECT_NAME}_HDRS
        serial_publisher.h
        ThirdParty/Timer-2.1/Event.h
        ThirdParty/Timer-2.1/Timer.h
        helper.h
        ReadStringSerial.h
        FunctionGenerator.h
        )

### Additional static libraries to include in the target.
# set(${PROJECT_NAME}_LIBS)

### Main sketch file
# set(${PROJECT_NAME}_SKETCH SerialPublisher.ino)

### Add project directories into the build
# add_subdirectory()
include_directories(
        ThirdParty/Timer-2.1
)

### Additional settings to add non-standard or your own Arduino libraries.
# For this example (libs will contain additional arduino libraries)
# An Arduino library my_lib will contain files in libs/my_lib/: my_lib.h, my_lib.cpp + any other cpp files
link_directories(

)

# For nested library sources replace ${LIB_NAME} with library name for each library
# set(_RECURSE true)

#### Additional settings for programmer. From programmers.txt
set(${PROJECT_NAME}_PROGRAMMER avrispmkii)
set(${PROJECT_NAME}_PORT COM5)
set(mega.upload.speed 115200)

## Verbose build process
set(${PROJECT_NAME}_AFLAGS -v)

generate_arduino_firmware(${PROJECT_NAME})


print_board_list()
print_programmer_list()
