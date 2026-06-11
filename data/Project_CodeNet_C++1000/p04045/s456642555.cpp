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

#define vi std::vector<int>
#define vl std::vector<ll>
#define floop(n) for(int i = 0; i < n; ++i)
#define print(x) std::cout << x << std::endl;

const ll INF = 1e18;

int main()
{
    int N, K, d, a;
    std::vector<bool> D(10, false);
    std::cin >> N >> K;

    floop(K)
    {
        std::cin >> d;
        D[d] = true;
    }

    for(int i = N; i < N*10; ++i)
    {
        a = i;
        while(a > 0)
        {
            d = a % 10;
            if(D[d])
                break;
            a /= 10;
        }

        if(a == 0)
        {
            N = i;
            break;
        }
    }

    print(N);
    return 0;
}