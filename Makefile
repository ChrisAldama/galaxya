TARGET := galaxya
CPPFLAGS := -g -std=c++11
LDFLAGS := -lsdl2 -lsdl2_image
CXX := g++

SRC_DIRS := ./
BUILD_DIR := ./build

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
INCLUDES := -I$(shell pwd)

$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS) 

$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

MKDIR_P := mkdir -p
