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
    int N, max=-1000, min=1000, res = 1000000, temp;
    std::cin >> N;
    vi A(N);

    floop(N)
    {
        std::cin >> A[i];
        if(max < A[i])
            max = A[i];
        if(min > A[i])
            min = A[i];
    }

    for(int i = min; i <= max; ++i)
    {
        temp = 0;
        for(int j = 0; j < N; ++j)
        {
            temp += ((A[j]-i)*(A[j]-i));
        }
        
        if(res > temp)
            res = temp;
    }

    print(res);
    return 0;
}