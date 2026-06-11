#include <bits/stdc++.h>
#define ll  long long

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, "\e[31;1m"); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\e[0m")
#else
    #define eprintf(...) 42
#endif

std::string solve(std::string& S)
{
    if ((1 == S.length() % 2 && S[0] == S[S.length() - 1])
     || (1 != S.length() % 2 && S[0] != S[S.length() - 1]))
    {
        return "Second";
    }
    return "First";
}

int main(void)
{
    std::string S;
    std::cin >> S;
    std::cout << solve(S) << std::endl;
    return 0;
}