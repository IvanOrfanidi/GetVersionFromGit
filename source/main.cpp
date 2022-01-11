#include <iostream>

extern const char* GIT_TAG;
extern const char* GIT_REV;
extern const char* GIT_BRANCH;

int main()
{
    std::cout << "Hello git version!" << std::endl;
    return EXIT_SUCCESS;
}