#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

int color[9];

int main()
{
    int N; std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        std::cin >> temp;
        for (int j = 1; j < 9; j++)
        {
            int disc = j * 400;
            if (temp - disc < 0)
            {
                color[j-1]++;
                break;
            } else if (temp >= 3200)
            {
                color[8]++;
                break;
            }
        }
    }

    int kind = 0;
    for (int i = 0; i < 8; i++)
    {
        if (color[i] > 0) kind++;
    }

    if (kind != 0)
        std::cout << kind << " " << kind + color[8] << std::endl;
    else
        std::cout << 1 << " " << kind + color[8] << std::endl;
    
    return 0;
}