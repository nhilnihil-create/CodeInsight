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
    std::string w;
    std::vector<char> key;
    std::map<char, int> cnt;

    std::cin >> w;
    int len = w.length();

    for(int i = 0; i < len; ++i)
    {
        if(w[i] >= 97 && w[i] <= 122)
        {
            if(cnt.count(w[i]))
                cnt[w[i]]++;
            else
            {
                cnt[w[i]] = 1;
                key.push_back(w[i]);
            }
        }
    }

    for(int i = 0; i < key.size(); ++i)
    {
        if(cnt[key[i]] % 2 == 1)
        {
            print("No");
            return 0;
        }
    }
    
    print("Yes");
    return 0;
}