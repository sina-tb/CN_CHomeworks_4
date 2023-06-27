OUT=tcp.out
CPPFLAGS=g++ -std=c++11 -g -Wall -Wextra -Wno-sign-compare
OBJS=TCP.o\
TCPRenoConnection.o\
TCPBBRConnection.o\
TCPNewRenoConnection.o\

SRC=./src/
INC=./include/

$(OUT): $(OBJS) main.cpp
	$(CPPFLAGS) $(OBJS) main.cpp -o $@ 

TCP.o: $(SRC)TCP.cpp $(INC)TCP.hpp
	$(CPPFLAGS) -c $(SRC)TCP.cpp -o $@

TCPRenoConnection.o: $(SRC)TCPRenoConnection.cpp $(INC)TCPRenoConnection.hpp
	$(CPPFLAGS) -c $(SRC)TCPRenoConnection.cpp -o $@

TCPNewRenoConnection.o: $(SRC)TCPNewRenoConnection.cpp $(INC)TCPNewRenoConnection.hpp
	$(CPPFLAGS) -c $(SRC)TCPNewRenoConnection.cpp -o $@

TCPBBRConnection.o: $(SRC)TCPBBRConnection.cpp $(INC)TCPBBRConnection.hpp
	$(CPPFLAGS) -c $(SRC)TCPBBRConnection.cpp -o $@

clean:
	rm -rf *.o *.out