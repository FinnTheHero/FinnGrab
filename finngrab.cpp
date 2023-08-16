#include <iostream>
#include <Windows.h>

void upTime ();
void ram ();
void screenResolution ();
void finnGrabVersion ();

int main() {
    
    finnGrabVersion();
    upTime();
    screenResolution();
    ram();

    return 0;
}

void finnGrabVersion () {
    std::cout << "FinnGrab Version: 0.1" << std::endl;
}

void upTime () {
    DWORD ticks = GetTickCount();

    DWORD seconds = ticks / 1000;
    DWORD minutes = seconds / 60;
    DWORD hours = minutes / 60;
    DWORD days = hours / 24;

    std::cout << "Uptime: " << days << "d " << hours % 24 << "h " << minutes % 60 << "m " << seconds % 60 << "s "<< std::endl;

}

void ram () {
    MEMORYSTATUSEX memoryStatus;

    memoryStatus.dwLength = sizeof(memoryStatus);
    GlobalMemoryStatusEx(&memoryStatus);

    ULONGLONG totalRAM = memoryStatus.ullTotalPhys;
    ULONGLONG usedRAM = totalRAM - memoryStatus.ullAvailPhys;

    int usedPercentage = (double)usedRAM / totalRAM * 100.0;

    std::cout << "RAM: " << usedRAM / (1024 * 1024) << " MB / " << totalRAM / (1024 * 1024) << " MB (" << usedPercentage << "%)" << std::endl;

}

void screenResolution () {
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    std::cout << "Resolution: " << screenWidth << " x " << screenHeight << std::endl;
}