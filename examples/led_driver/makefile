ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	CLEANUP = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	CLEANUP = rm -f
	MKDIR = mkdir -p
  endif
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

C_COMPILER=gcc

UNITY_ROOT=../..

CFLAGS=-std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition

TARGET_BASE1=test_unity_led_driver
TARGET1 = $(TARGET_BASE1)$(TARGET_EXTENSION)
SRC_FILES1=\
  $(UNITY_ROOT)/src/unity.c \
  $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
  test/led_driver_test.c \
  test/led_driver_test_runner.c \
  src/led_driver.c \
  ../mocks/Runtime_error_stub.c \
  test_unity_led_driver.c
INC_DIRS=-Isrc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src -I$(UNITY_ROOT)/examples/mocks 
SYMBOLS=-DUNITY_FIXTURE_NO_EXTRAS

all: clean default

default:
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET1)
	- ./$(TARGET1) -v

clean:
	$(CLEANUP) $(TARGET1)

ci: CFLAGS += -Werror
ci: default