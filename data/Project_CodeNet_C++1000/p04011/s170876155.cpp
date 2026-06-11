#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <math.h>

typedef long long ll;
typedef unsigned long long ull;

#define vi std::vector<int>
#define vl std::vector<ll>
#define floop(n) for(int i = 0; i < n; ++i)
#define print(x) std::cout << x << std::endl;

const ll INF = 1e18;

int main()
{
    int N, K, X, Y;
    std::cin >> N;
    std::cin >> K;
    std::cin >> X;
    std::cin >> Y;

    if(N <= K)
    {
        print((X*N));
    }

    else
    {
        print((X*K + Y*(N-K)));
    }

    return 0;
}