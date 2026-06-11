#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;
    bool ans = true;

    for (int i = 0; i < str.size(); i++) {
        if (str.at(i) == 'd') {
            if ((i + 5) < str.size() && str.substr(i, 6) == "dreamd") {
                i += 4;
                continue;
            }
            if ((i + 7) < str.size()) {
                if (str.substr(i, 8) == "dreamera") {
                    i += 4;
                    continue;
                }
                if (str.substr(i, 8) == "dreamere"
                    || str.substr(i, 8) == "dreamerd") {
                    i += 6;
                    continue;
                }
            }
            if (((i + 4) == (str.size() - 1) && str.substr(i, 5) == "dream")
                || ((i + 6) == (str.size() - 1) && str.substr(i, 7) == "dreamer")) {
                break;
            }
        }
        if (str.at(i) == 'e') {
            if ((i + 5) < str.size()) {
                if (str.substr(i, 6) == "erased"
                    || str.substr(i, 6) == "erasee") {
                    i += 4;
                    continue;
                }
            }
            if ((i + 6) < str.size()) {
                if (str.substr(i, 7) == "eraserd"
                    || str.substr(i, 7) == "erasere") {
                    i += 5;
                    continue;
                }
            }
            if (((i + 4) == (str.size() - 1) && str.substr(i, 5) == "erase")
                || ((i + 5) == (str.size() - 1) && str.substr(i, 6) == "eraser")) {
                break;
            }
        }
        ans = false;
        break;
    }
    if (ans)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
    return 0;
}
