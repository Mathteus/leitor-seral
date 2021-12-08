#ifndef MYSERIAL_H
#define MYSERIAL_H

//includes para ler e escrever serial
#include "libserial/SerialPort.h"
#include "libserial/SerialStream.h"

//includes c++
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace LibSerial;

enum Portas { S0=1, S1=2, USB0=3 };
#define BUFFER_SIZE 256

class MySerial {
private:
    LibSerial::SerialPort porta_serial;
    LibSerial::SerialStream serial_stream;
    std::string mensagem;
    char input_buffer[BUFFER_SIZE];
    char output_buffer[BUFFER_SIZE];

public:
    MySerial(Portas porta);
    ~MySerial();

    std::string ler();
    void escrever(std::string msg);
    void setVelocidade(LibSerial::BaudRate velocity);
};

#endif // MYSERIAL_H
