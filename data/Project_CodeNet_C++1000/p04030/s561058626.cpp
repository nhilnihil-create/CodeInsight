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
    std::string s, res="";
    std::cin >> s;

    int len = s.length();

    floop(len)
    {
        if(s[i] == 'B')
        {
            if(res != "")
                res.pop_back();
        }

        else
            res += s[i];
    }

    print(res);
    return 0;
}