// FinnGrab will display information as well as logo using line-by-line structure

#include <iostream>
#include <Windows.h>
#include <vector>

std::vector<std::string> windows10Logo () {
    std::vector<std::string> artArray = {
        "                                    ..       ",
        "                             ..oodMMMM       ",
        "                    ..oodMMMMMMMMMMMMM       ",
        "        ...oodMMM  MMMMMMMMMMMMMMMMMMM       ",
        "   oooMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM       ",
        "   MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM       ",
        "   MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM       ",
        "   MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM       ",
        "   MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM       ",
        "   MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM       ",
        "                                             ",
        "   MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM       ",
        "   MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM       ",
        "   MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM       ",
        "   MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM       ",
        "   MMMMMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM       ",
        "   ^^^MMMMMMMMMMM  MMMMMMMMMMMMMMMMMMM       ",
        "          ```^^^^  MMMMMMMMMMMMMMMMMMM       ",
        "                        ```^^^^^^MMMMM       "
    };

    return artArray;
}

void finnGrabVersion () {
    std::cout << "FinnGrab Version: 0.2" << std::endl;
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

int main () {
    // Create an array of pointers to the functions
    void (*functionPointers[])() = { finnGrabVersion, upTime, screenResolution, ram };

    // Calculate number of elements in the array
    int numFunctions = sizeof(functionPointers) / sizeof(functionPointers[0]);

    // Get logo art
    std::vector<std::string> artArray = windows10Logo();
 
    // Calculate the number of rows in the array
    std::size_t artArrayLength = artArray.size();    

    // Create iterator for loop
    int iterator = 0;
   
    // Find if art is larger or system information and make iterator based on that
    if (artArrayLength > numFunctions) {
        iterator = artArrayLength;
    } else {
        iterator = numFunctions;
    }
    
    // Place holder when system information is more than logo
    std::string placeHolder = "                                             ";
    
    
    // Use loop to call each function as well as logo ASCII art
    for (int i=0; i < iterator; i++) {
        if (artArrayLength > i) {
            std::cout << artArray[i];
        } else {
            std::cout << placeHolder;
        }

        if (numFunctions > i) {
            functionPointers[i]();
        } else {
            std::cout << std::endl;
        }
    }
    return 0;
}