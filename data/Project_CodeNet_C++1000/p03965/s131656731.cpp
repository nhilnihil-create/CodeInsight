#include <bits/stdc++.h>
#define ll  long long

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, "\e[31;1m"); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\e[0m")
#else
    #define eprintf(...) 42
#endif

ll solve(const std::string& T)
{
    return (T.size() / 2) - std::accumulate(T.begin(), T.end(), 0, [](int a, char v){
        if ('p' == v)
        {
            return a + 1;
        }
        return a;
    });
}

int main(void)
{
    std::string T;
    std::cin >> T;
    std::cout << solve(T) << std::endl;
    return 0;
}