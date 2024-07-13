#ifndef ALGORITHM_LIBRARY_LCS_H
#define ALGORITHM_LIBRARY_LCS_H

#include <string>

class LCS {
public:
    LCS(const std::string& str1, const std::string& str2);

    int solve();

private:
    std::string str1;
    std::string str2;
};

#endif //ALGORITHM_LIBRARY_LCS_H
