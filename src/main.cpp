#include "myserial.h"

int main(int argc, char** argv){
    MySerial serial(Portas::USB0);
    std::string str;

    while (true) {
        str = serial.ler();
        std::cout << str << "\n";
    }

    return 0;
}
