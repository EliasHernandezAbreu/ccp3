#include "TuringMachine.hpp"
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>

int main (int argc, char *argv[]) {
    // Process args
    const char* file_path = NULL;
    for (int arg = 1; arg < argc; arg++) {
        if (strcmp(argv[arg], "-h") == 0) {
            printf("Turing machine simulator.\n"
                   "USAGE:\n"
                   "tm <FILEPATH> - create a Turing machine from the file\n"
                   "OPTIONS:\n"
                   "-h - print this help and quit\n");
            return 0;
        }
        file_path = argv[arg];
    }

    // Check args
    if (file_path == NULL) {
        printf("You must specify a file with the Turing machine definition."
               " Use \"%s -h\" for more help.\n", argv[0]);
        return 1;
    }

    std::ifstream input_stream(file_path);
    if (!std::filesystem::exists(file_path)) {
        printf("Could not open file \"%s\"\n", file_path);
        return 1;
    }
    std::ifstream input(file_path);
    if (!input.is_open()) {
        printf("Could not open file \"%s\"\n", file_path);
        return 1;
    }

    std::stringstream file_contents_buf;
    file_contents_buf << input.rdbuf();
    std::string file_contents = file_contents_buf.str();

    TuringMachine turing_machine(file_contents);

    return 0;
}
