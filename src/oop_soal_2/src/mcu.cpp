#include "../include/mcu.hpp"

MCU::MCU(float cpu_speed, int memory, string os, string name, int volt)
    : cpu_speed(cpu_speed), memory(memory), os(os), name(name), volt(volt)
{
    cout << "[KONSTRUKTOR MCU] : Objek " << name << " berhasil dibuat." << endl;
}

void MCU::showSpek() {
    cout << "[BASE MCU] : " << name << " | CPU: " << cpu_speed
         << "GHz | RAM: " << memory << "MB | OS: " << os
         << " | Volt: " << volt << "V" << endl;
}

MCU::~MCU() {
    cout << "[DESTRUKTOR MCU] : Objek base " << name << " dibersihkan." << endl;
}

void MCU::nambah_volt(int penambahan_voltase) {
    volt += penambahan_voltase;
}

void MCU::ganti_os(string new_os) {
    os = new_os;
}