CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = nzengi_method
SRCS = Main.cpp DynamicParameters.cpp FractalDecomposition.cpp ErrorCorrection.cpp Compute.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)
