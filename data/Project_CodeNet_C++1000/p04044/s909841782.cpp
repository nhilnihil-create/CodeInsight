#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int n, l;
    std::cin >> n >> l;

    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> s[i];
    }

    std::sort(s.begin(), s.end());
    for (int i = 0; i < n; i++)
    {
        std::cout << s[i];
    }

    std::cout << "\n";
}