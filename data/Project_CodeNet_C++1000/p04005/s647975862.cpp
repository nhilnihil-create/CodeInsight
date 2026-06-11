#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

#define rep(i, o) for (int i = 0; i < (o);i++)
#define rep_s(i, o) for (int i = 1; i < (o);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<(int)(b);i++)
#define NUM 1e5

typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }


template<class T>
bool chmax(T &a, const T &b) {
    if (a < b)
    {
        return b;
    }
    return a; 
}

template<class T>
bool chmin(T &a, const T &b) {
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0; 
}

ull middle(ull a, ull b, ull c) 
{ 
    // Checking for b 
    if ((a <= b && b < c) || (c <= b && b < a)) 
       return b; 
  
    // Checking for a 
    else if ((b <= a && a < c) || (c <= a && a < b)) 
       return a; 
  
    else
       return c; 
} 

int main() {
    const ull INF = 1e9 + 7;
    ull a, b, c;
    cin >> a >> b >> c;
    ull blocks[3] = {a, b, c};
    ull min_block = min({a,b,c});
    ull max_block = max({a,b,c});
    ull mid_block = middle(a,b,c);

    ull min_blocks_for_cuboid = 0;
    if (a%2 != 0 && b%2 != 0 && c%2 != 0) min_blocks_for_cuboid = min({a*b, b*c, c*a});
    else min_blocks_for_cuboid = 0;
    cout << min_blocks_for_cuboid << endl;
    return 0;
}