#include <iostream>
#include <vector>

int main()
{
    int n; std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i];
        v[i]--;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == v[v[i]])
        {
            cnt++;
        }
    }
    std::cout << (cnt/2) << std::endl;
    return 0;
}
