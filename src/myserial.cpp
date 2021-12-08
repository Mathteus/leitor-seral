#include "myserial.h"

MySerial::MySerial(Portas porta) {
    switch (porta) {
        case Portas::S0:
            porta_serial.Open("/dev/ttyS0");
            porta_serial.SetBaudRate(LibSerial::BaudRate::BAUD_115200);
            porta_serial.SetCharacterSize(LibSerial::CharacterSize::CHAR_SIZE_8);
            porta_serial.SetFlowControl(LibSerial::FlowControl::FLOW_CONTROL_DEFAULT);
            porta_serial.SetParity(LibSerial::Parity::PARITY_DEFAULT);
            porta_serial.SetStopBits(LibSerial::StopBits::STOP_BITS_1);
        break;

        case Portas::S1:
            porta_serial.Open("/dev/ttyS1");
            porta_serial.SetBaudRate(LibSerial::BaudRate::BAUD_115200);
            porta_serial.SetCharacterSize(LibSerial::CharacterSize::CHAR_SIZE_8);
            porta_serial.SetFlowControl(LibSerial::FlowControl::FLOW_CONTROL_DEFAULT);
            porta_serial.SetParity(LibSerial::Parity::PARITY_DEFAULT);
            porta_serial.SetStopBits(LibSerial::StopBits::STOP_BITS_1);
        break;

        case Portas::USB0:
            //abrindo porta serial
            serial_stream.Open("/dev/ttyUSB0");

            //tamanho da velocidade de transmisao da porta
            serial_stream.SetBaudRate(LibSerial::BaudRate::BAUD_300);

            // Configurando o Tamanho do Caráter
            serial_stream.SetCharacterSize(LibSerial::CharacterSize::CHAR_SIZE_8);

            // Configurando o Tipo de Controle de Fluxo
            serial_stream.SetFlowControl(LibSerial::FlowControl::FLOW_CONTROL_DEFAULT);

            // Definir o tipo de paridade
            serial_stream.SetParity(LibSerial::Parity::PARITY_DEFAULT);

            // Definindo o número de bits de parada
            serial_stream.SetStopBits(LibSerial::StopBits::STOP_BITS_1);
        break;

        default: break;
    }


}

std::string MySerial::ler() {
    if (porta_serial.IsOpen()) {
        mensagem = "";
        porta_serial.Read(mensagem, BUFFER_SIZE);

    }

    if (serial_stream.IsOpen()) {
        for (int a=0; a<BUFFER_SIZE; a++)
            input_buffer[a] = ' ';

        serial_stream >> input_buffer;
        mensagem = "";

        for (int a=0; a<BUFFER_SIZE; a++)
            mensagem += input_buffer[a];
    }

    return mensagem;
}

void MySerial::escrever(std::string msg) {
    if (porta_serial.IsOpen())
        porta_serial.Write(msg);

    if (serial_stream.IsOpen())
        serial_stream << msg;
}

void MySerial::setVelocidade(LibSerial::BaudRate velocity) {
    if (porta_serial.IsOpen())
        porta_serial.SetBaudRate(velocity);

    if (serial_stream.IsOpen())
        serial_stream.SetBaudRate(velocity);
}

MySerial::~MySerial() {
    if (porta_serial.IsOpen())
        porta_serial.Close();

    if (serial_stream.IsOpen())
        serial_stream.Close();
}
