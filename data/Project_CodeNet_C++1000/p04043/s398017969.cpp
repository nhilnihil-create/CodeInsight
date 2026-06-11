#include <bits/stdc++.h>

const std::string YES = "YES";
const std::string NO = "NO";

void solve(std::array<unsigned, 3>& a)
{
    std::sort(a.begin(), a.end());
    std::cout << (a[0] == 5 && a[1] == 5 && a[2] == 7 ? YES : NO) << '\n';
}

int main()
{
    std::array<unsigned, 3> a;
    std::cin >> a[0] >> a[1] >> a[2];
    solve(a);
    return 0;
}

