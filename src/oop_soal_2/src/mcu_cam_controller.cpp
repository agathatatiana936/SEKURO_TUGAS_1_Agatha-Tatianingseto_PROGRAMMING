#include "../include/mcu_cam_controller.hpp"

int mcu_cam_controller::count_detected_obj = 0;

mcu_cam_controller::mcu_cam_controller(float cpu_speed, int memory, string os, string nama, int volt, string obj_detected)
    : MCU(cpu_speed, memory, os, nama, volt), obj_detected(obj_detected)
{
    count_detected_obj++;
    cout << "[KONSTRUKTOR CAM] : Komponen kamera untuk " << name << " siap digunakan." << endl;
}

void mcu_cam_controller::showSpek() {
    cout << "[SPEK MCU_CAM] : " << name
         << " | [CPU] : " << cpu_speed << " GHz"
         << " | [RAM] : " << memory << " MB"
         << " | [OS] : " << os
         << " | [Volt] : " << volt << "V"
         << " | [Last Obj] : " << obj_detected
         << " | [Total Detect] : " << count_detected_obj << endl;
}

void mcu_cam_controller::detect_other_object(string other, bool moving) {
    obj_detected = other;
    count_detected_obj++;
    if (moving){
        cout << "[CAM SYSTEM] : Terdeteksi " << other << " (Status: Bergerak/Aktif)" << endl;
    } else { 
        cout << "[CAM SYSTEM] : Terdeteksi " << other << " (Status: Diam/Statis)" << endl;
    }    
}

void mcu_cam_controller::nambah_volt(int penambahan_voltase) {
    volt += penambahan_voltase;
    cout << "Voltase " << name << " berhasil dinaikkan ke: " << volt << "V" << endl;
}

void mcu_cam_controller::ganti_os(string new_os) {
    os = new_os;
    cout << "[CAM UPDATE] : " << name << " migrasi OS ke " << os << endl;
}

mcu_cam_controller::~mcu_cam_controller() {
    cout << "[DESTRUKTOR] : Objek " << name << " telah dihapus dari memori." << endl;
}