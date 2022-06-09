#include<iostream>
#include<regex>
#include<windows.h>
#include<fstream>
#include<filesystem>

int main(int argc, char **argv)
{
    int value;
    char* p_argv;
    std::string def_arg_txt;
    std::ifstream def_arg;

    def_arg_txt = argv[0];
    std::filesystem::path filepath = def_arg_txt.c_str();

    def_arg_txt = filepath.generic_string<char>();
    def_arg_txt.erase(def_arg_txt.begin() + def_arg_txt.rfind('/'), def_arg_txt.end());
    def_arg_txt += "/def_arg.txt";


    def_arg.open(def_arg_txt.c_str());
    if (!def_arg) {
        printf("ERROR: Can't open def_arg.txt!!\n");
        return -1;
    }

    def_arg_txt = std::string((std::istreambuf_iterator<char>(def_arg)), std::istreambuf_iterator<char>());


    def_arg.close();


    value = 1;
    for (; value < argc; value++)
    {
        def_arg_txt.push_back(' ');
        def_arg_txt += argv[value];
    }

    printf("execute \"%s\"\n", def_arg_txt.c_str());
    system(def_arg_txt.c_str());


    return 0;
}