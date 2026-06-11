#include <bits/stdc++.h>
#define ll  long long

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, "\e[31;1m"); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\e[0m")
#else
    #define eprintf(...) 42
#endif

std::string solve(std::string& S)
{
    int t = 0;
    for (int i = S.length() - 1; -1 < i; i--)
    {
#if true
        eprintf("DEBUG1: %d %s\n", i, S.c_str());
#endif
        if (0 == i || i == S.length() - 1)
        {
            continue;
        }
        if (S[i - 1] != S[i + 1])
        {
            S = S.substr(0, i) + S.substr(i + 1);
            t++;
            i++;
        }
    }
#if true
    eprintf("DEBUG2: %s\n", S.c_str());
#endif

    if (1 == t % 2)
    {
        return "First";
    }
    return "Second";
}

int main(void)
{
    std::string S;
    std::cin >> S;
    std::cout << solve(S) << std::endl;
    return 0;
}