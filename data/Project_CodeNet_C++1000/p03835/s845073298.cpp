#include <iostream>

int main(){
    int k, s;
    std::cin >> k >> s;

    int count = 0;
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if ((s - i - j <= k) && (i + j <= s))
            {
                count++;
            }
        }
    }
    
    std::cout << count << std::endl;

    return 0;
}