#include "cesarcypher.h"
#include <fstream>
#include <filesystem>

constexpr int smallBufferSize = 8192;
constexpr size_t bigBufferSize = 131072;

void inline cypher(char* temp,const size_t& bufferSize) {
    for (size_t i = 0; i < bufferSize;i += 6) {
        temp[i] -= 5;
    }
}

void cesarCypher(const std::string filePath) {
    std::string tempFile = filePath;
    tempFile = tempFile.append("temp.txt");

    std::ifstream originalFile(filePath, std::ios_base::binary);

    if (originalFile.is_open()) {
        std::ofstream cypherFile(tempFile, std::ios_base::binary);
        while (!originalFile.eof()) {
            char fileLine[smallBufferSize];
            if (originalFile.read(fileLine, smallBufferSize)) {
                cypher(fileLine, smallBufferSize);
                cypherFile.write(fileLine, originalFile.gcount());
            }
            else {
                char* bigBuffer = new char[bigBufferSize];
                if(originalFile.read(bigBuffer, bigBufferSize)){
                    cypher(bigBuffer,bigBufferSize);
                    cypherFile.write(bigBuffer, originalFile.gcount());
                }
                delete[] bigBuffer;
            }
        }
        originalFile.close();
        cypherFile.close();
       // std::filesystem::remove(filePath);
       // std::filesystem::rename(tempFile, filePath);
 
    }
}