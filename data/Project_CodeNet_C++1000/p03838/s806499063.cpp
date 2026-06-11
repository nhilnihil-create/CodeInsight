#pragma comment(linker, "/STACK:1024000000,1024000000")
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;

#define rep(i , a , b) for(register int i=(a);i<=(b);i++)
#define per(i , a , b) for(register int i=(a);i>=(b);i--)
#define ms(s) memset(s, 0, sizeof(s))
#define squ(x) (x)*(x)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll , ll> pi;
typedef unordered_map<int,int> un_map;
template<class T>
inline void read (T &x) {
    x = 0;
    int sign = 1;
    char c = getchar ();
    while (c < '0' || c > '9') {
        if ( c == '-' ) sign = - 1;
        c = getchar ();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar ();
    }
    x = x * sign;
}

const int maxn = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const ll INF = ll(1e15);
const int mod = 1e9+7;
const double PI = acos(-1);
//#define LOCAL


int main(int argc, char * argv[])
{

    ll x,y;
    read(x);read(y);
    ll ans = INF;
    ans=min(ans,abs(x+y)+1);
    if(x>=y) ans=min(abs(x-y)+2,ans);
    else ans=min(ans,abs(x-y));
    cout<<ans<<endl;
    return 0;
}