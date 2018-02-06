#pragma once

#include <cstdio>
#include <cstdlib>


#include <iostream>
#include <fstream>


#include <sstream>
#include <string>

namespace ArtabanRenderer {
	
	
	std::string read_file_ctype(const char* _filePath);

	std::string read_file_stream(const char* _filePath);
}