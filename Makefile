CXX = g++
CXXFLAGS = -std=c++11

TARGET = hacker-rm
OBJS = hacker-rm.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

hacker-rm.o: hacker-rm.cpp
	$(CXX) $(CXXFLAGS) -c hacker-rm.cpp

clean:
	rm -f $(TARGET) $(OBJS)
