#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for(int i = 0; i < N; i++)
    {
        std::cin >> a[i];
    }

    int ans = 0;
    for(int usa = 0; usa < N; usa++)
    {
        int aiteUsa = a[usa];

        if(a[aiteUsa - 1] <= -1) continue;

        if(a[aiteUsa - 1] == usa + 1)
        {
            ans++;
            a[aiteUsa - 1] = -1;   // 逆向きのペアをかぞえないため 
        }
    }

    std::cout << ans << std::endl;

    return 0;
}