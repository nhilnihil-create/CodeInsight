#include <iostream>

int main()
{
    int h, w;
    std::cin >> h >> w;

    std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::string s;
            std::cin >> s;

            if (s == "snuke") {
                std::cout << alpha[j] << i + 1 << std::endl;
            }
        }
    }
}
