#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>


int main()
{
    int N;
    std::cin >> N;
    std::vector<int> s(N, 0);
    int ans = 0;
    for (int i = 0; i<s.size(); i++)
    {
        std::cin >> s[i];
        ans += s[i];
    }
    if (ans % 10 != 0)
    {
        std::cout << ans << std::endl;
        return 0;
    }
    std::sort(s.begin(), s.end());
    
    int m = 0; bool is_all_ten_time = true;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] % 10 != 0)
        {
            is_all_ten_time = false;
            m = s[i];
            break;
        }
    }
    if (is_all_ten_time)
    {
        std::cout << 0 << std::endl;
    } else {
        std::cout << ans - m << std::endl;
    }

    
    return 0;
}