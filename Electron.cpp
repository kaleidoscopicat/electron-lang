#include <iostream>
#include <stdio.h>
#include <ostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "File not provided" << '\n';
        return 1;
    }

    std::string filePath = argv[1];
    std::string directory;
    const size_t lSlashIndex = filePath.rfind("\\");
    if (std::string::npos != lSlashIndex)
    {
        directory = filePath.substr(0, lSlashIndex);
    }
    
    std::cout << "File: " << filePath << '\n';

    std::ifstream file(filePath);
    if (!file)
    {
        std::cerr << "File not found" << '\n';
        return 1;
    }

    std::cout << "File " + filePath + " opened" << '\n';
    std::string line;

    std::ofstream buildOutput(directory + R"(\output.txt)", std::ios::app);
    buildOutput << "nerd data goes here\n";
    while (std::getline(file, line))
    {
        for (std::string::size_type i = 0; i < line.size(); ++i)
        {
            char c = line[i];
            
            buildOutput << c << "[" << i << "]";
        }
            
        buildOutput << '\n';
    }

    buildOutput << "[END OF OUTPUT]" << '\n';
    file.close();
    buildOutput.close();
    
    return 0;
}
