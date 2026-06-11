/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <stack>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#include <functional>
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi   vector<int> 
#define   co(x)  cout << x << '\n' 
#define   dbg(x)  cerr << #x << " = " << x << '\n' 
#define   bitcount(x)  (int)__builtin_popcount(x) 
#define   sz(x)  (int)x.size()
#define   all(a) a.begin(),a.end() 
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

inline void solve(){
    string  s;
    cin >> s;
    vi cnt(26, 0) ; 
    int n = sz(s) , ans = 0 ;
    for (int  i = 0 ; i < n ;i++ ) cnt[s[i]-'a']++ ; 
    ans = 1 + (n*(n-1)/2) ; 
    for (int i=0;i<26;i++){
    	if (cnt[i] > 0){
    		ans -= ( cnt[i] * ( cnt[i]-1 ) / 2) ; 
    	}
    }
    co ( ans ) ; 
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
