#-----------------------------------------------------------
# Macro definitions
CXXFLAGS = -O1 -g -Wall -std=c++17
OBJ = main.o tools.o Block.o Blockchain.o BlockSerial.o Inventory.o Population.o Serial.o Simulator.o SPtr.o
TARGET = blockchain
#-----------------------------------------------------------
# Rules
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ)
clean:
	rm -f $(OBJ) $(TARGET)
#-----------------------------------------------------------
# Dependencies
main.o: main.cpp
tools.o: tools.cpp tools.hpp
Block.o: Block.cpp Block.hpp
Blockchain.o: Blockchain.cpp Blockchain.hpp
BlockSerial.o: BlockSerial.cpp BlockSerial.hpp
Inventory.o: Inventory.cpp Inventory.hpp
Population.o: Population.cpp Population.hpp
Serial.o: Serial.cpp Serial.hpp
Simulator.o: Simulator.cpp Simulator.hpp
SPtr.o: SPtr.cpp SPtr.hpp