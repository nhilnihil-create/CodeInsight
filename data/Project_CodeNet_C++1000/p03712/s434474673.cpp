#include<iostream>
#include<string>
#include<vector>

int main() {
    int h, w;
    std::cin >> h >> w;
    std::vector<std::vector<char>> a(h, std::vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cin >> a[i][j];
        }
    }
        for (int i = -1; i < h + 1; i++)
        {
            for (int j = -1; j < w + 1; j++)
            {
                if (i >= 0 && i < h && j >= 0 && j < w)
                {
                    std::cout << a[i][j];
                }
                else
                {
                    std::cout << '#';
                }
            }
            std::cout << "\n";
        }
}