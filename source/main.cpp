#include <iostream>

extern const char* GIT_TAG;
extern const char* GIT_REV;
extern const char* GIT_BRANCH;

int main()
{
    std::cout << "git branch: \'" << GIT_BRANCH << '\'' << std::endl;
    std::cout << "git revision: \'" << GIT_REV << '\'' << std::endl;
    std::cout << "git tag: \'" << GIT_TAG << '\'' << std::endl;
    return EXIT_SUCCESS;
}