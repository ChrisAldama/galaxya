CPPFLAGS := -g -std=c++11
LDFLAGS := -lsdl2 -lsdl2_image
CXX := g++
TARGET := galaxya
OBJ := screen.o main.o event_loop.o sprite.o application.o

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CPPFLAGS)

$(TARGET): $(OBJ)
	$(CXX) $(CPPFLAGS) $(LDFLAGS) $^ -o $@

all: $(TARGET)