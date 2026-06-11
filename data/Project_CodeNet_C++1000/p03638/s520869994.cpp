#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int h, w, n;
    std::cin >> h >> w >> n;
    std::vector<int> c(h * w);

    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        int a;
        std::cin >> a;
        for (int j = 0; j < a; j++)
        {
            c[k] = i;
            k++;
        }
    }
    
    k = 0;
    for (int i = 0; i < h; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < w; j++)
            {
                std::cout << c[k] << " ";
                k++;
            }
            std::cout << std::endl;
        }
        else
        {
            std::vector<int> tmp(w);
            for (int j = 0; j < w; j++)
            {
                tmp[j] = c[k];
                k++;
            }
            for (int j = w - 1; j >= 0; j--)
            {
                std::cout << tmp[j] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}