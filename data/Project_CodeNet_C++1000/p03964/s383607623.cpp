#include <bits/stdc++.h>
#define ll  long long

ll solve(const std::vector<std::pair<int, int>>& TA)
{
    ll T = 1, A = 1;
    for (auto itr = TA.begin(); itr != TA.end(); ++itr)
    {
        ll t = (T + itr->first - 1) / itr->first;
        ll a = (A + itr->second - 1) / itr->second;
        ll n = std::max(t, a);
        T = n * itr->first;
        A = n * itr->second;
    }
    return T + A;
}

int main(void)
{
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> TA(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> TA[i].first >> TA[i].second;
    }
    std::cout << solve(TA) << std::endl;

    return 0;
}