#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file-to-erase>" << std::endl;
        return 1;
    }

    const char* filePath = argv[1];
    struct stat fileStat;

    if (stat(filePath, &fileStat) != 0) {
        std::cerr << "Error: File does not exist or cannot be accessed." << std::endl;
        return 1;
    }

    std::ofstream file(filePath, std::ios::binary);
    if (!file) {
        std::cerr << "Error: Cannot open file for writing." << std::endl;
        return 1;
    }

    for (off_t i = 0; i < fileStat.st_size; i++) {
        file.put('\0');
    }
    file.close();

    if (unlink(filePath) != 0) {
        std::cerr << "Error: Cannot delete file." << std::endl;
        return 1;
    }

    std::cout << "File successfully overwritten and deleted." << std::endl;
    return 0;
}
