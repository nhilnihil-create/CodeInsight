#include <bits/stdc++.h>

void solve(std::vector<std::string>& s)
{
    std::sort(s.begin(), s.end());

    std::cout << std::accumulate(s.begin(), s.end(), std::string()) << '\n';
}

int main()
{
    size_t n, l;
    std::cin >> n >> l;

    std::vector<std::string> s(n);
    for (size_t i = 0; i < n; ++i)
        std::cin >> s[i];

    solve(s);

    return 0;
}

