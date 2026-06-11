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
    string  s ; 
    cin >> s ; 
    for (int i=1;i<sz(s);i++){
    	if (s[i] == s[i-1]){
    		co(i<<" "<<i+1);
    		return;
    	}
    	if (i>1){
    		if (s[i] == s[i-2]){
    			co(i-1<<" "<<i+1);
    			return;
    		}
    	}
    }
    co(-1<<" "<<-1);
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
