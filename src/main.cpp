/**
 * Complejidad Computacional
 * Practica 3 - Turing machine
 * 
 * @author Elías Hernández Abreu
 * @brief Main file
 */

#include "TuringMachine.hpp"
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>

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

    // Read file
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

    // Run turing machine
    try {
        TuringMachine turing_machine(file_contents);
        std::string word = "";
        std::cout << "Enter a word to analyse (use \".\" to exit): ";
        while (std::getline(std::cin, word)) {
            if (word == ".") break;
            bool belongs = turing_machine.run(word);
            if (belongs) printf("\nThe word %s was recognized\n", word.c_str());
            else printf("\nThe word %s was NOT recognized\n", word.c_str());
            std::cout << "\nEnter a word to analyse (use \".\" to exit): ";
        }

    } catch (std::runtime_error e) {
        printf("%s\n", e.what());
    }

    return 0;
}
