#include <windows.h>
#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    SYSTEM_INFO inf;
    GetSystemInfo(&inf);
    MEMORYSTATUSEX memStatus{};
    memStatus.dwLength = sizeof(MEMORYSTATUSEX); 
    GlobalMemoryStatusEx(&memStatus);

    std::cout << "---- Информация о системе ----" << std::endl;
    std::cout << "Размер страницы виртуальной памяти: " << inf.dwPageSize << " bytes" << std::endl;
    std::cout << "Число процессоров: " << inf.dwNumberOfProcessors << std::endl;
    std::cout << "Архитектура процессора: ";
    switch (inf.wProcessorArchitecture) {
    case PROCESSOR_ARCHITECTURE_INTEL:
        std::cout << "x86" << std::endl;
        break;
    case PROCESSOR_ARCHITECTURE_AMD64:
        std::cout << "x64" << std::endl;
        break;
    case PROCESSOR_ARCHITECTURE_ARM:
        std::cout << "ARM" << std::endl;
        break;
    }

    std::cout << "\n---- Адреса памяти ----" << std::endl;
    std::cout << "Минимальный адрес доступного адресного пространства: " << std::hex << inf.lpMinimumApplicationAddress << std::endl;
    std::cout << "Максимальный адрес доступного адресного пространства: " << std::hex << inf.lpMaximumApplicationAddress << std::endl;
    std::cout << "Гранулярность резервирования регионов адресного пространства: " << std::dec << inf.dwAllocationGranularity << " bytes" << std::endl;

    std::cout << "\n---- Информация о памяти ----" << std::endl;
    std::cout << "Объем физической памяти: " << memStatus.ullTotalPhys / (1024 * 1024) << " MB" << std::endl;
    std::cout << "Доступная физическая память: " << memStatus.ullAvailPhys / (1024 * 1024) << " MB" << std::endl;
    std::cout << "Объем виртуальной памяти: " << memStatus.ullTotalVirtual / (1024 * 1024) << " MB" << std::endl;
    std::cout << "Доступная виртуальная память: " << memStatus.ullAvailVirtual / (1024 * 1024) << " MB" << std::endl;

    return 0;
}
