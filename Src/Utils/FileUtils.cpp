
#include "Utils/FileUtils.h"

namespace ArtabanRenderer {
	
	
	std::string read_file_ctype(const char* _filePath)
	{
		FILE* file = fopen(_filePath, "rb");
		fseek(file, 0, SEEK_END);
		unsigned int length = ftell(file);
		char* data = new char[length + 1];

		fseek(file, 0, SEEK_SET);
		memset(data, 0, length + 1);
		fread(data, length, 1, file);
		fclose(file);

		std::string result(data);
		delete[] data;

		return result;
	}

	std::string read_file_stream(const char* _filePath)
	{
		using std::ifstream;
		ifstream inFile(_filePath);
		std::stringstream code;
		code << inFile.rdbuf();
		inFile.close();
		
		return code.str();
	}
}