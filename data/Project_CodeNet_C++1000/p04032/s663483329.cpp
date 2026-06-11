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
    std::string s;
    std::cin >> s;
    int len = s.length(), left=-1, right=-1;

    if(len == 2)
    {
        if(s[0] == s[1])
        {
            print("1 2");
        }
        else
        {
            print("-1 -1");
        }
    }

    else
    {
        for(int i = 0; i < len-2; ++i)
        {
            if(s[i] == s[i+1] || s[i] == s[i+2])
            {
                left = i+1;
                right = i+3;
                break;
            }
        }

        print(left << " " << right);
    }

    return 0;
}