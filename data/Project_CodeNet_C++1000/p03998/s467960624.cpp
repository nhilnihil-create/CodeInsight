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
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi  vector<int> 
#define   dbg(x)  cerr << #x << " = " << x << '\n'
#define   sz(x)  (int)x.size()
#define   all(a) (a.begin(),a.end())
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

inline void solve(){
    string  a,b,c;
    cin>>a>>b>>c;
    int  n1=sz(a) ,n2=sz(b), n3=sz(c) ; 
    int i,j,k;
    char cur=a[0];
    while (true){
    	if (cur=='a') {
    		if (sz(a)==0) cout << "A"<< endl,exit(0);
    		else {
    			cur=a[0];
    			a.erase(a.begin());
    		}
    	}
    	else if (cur=='b') {
    		if (sz(b)==0) cout << "B"<< endl,exit(0);
    		else {
    			cur=b[0];
    			b.erase(b.begin());
    		}
    	}
    	else {
    		if (sz(c)==0) cout << "C"<< endl,exit(0);
    		else {
    			cur=c[0];
    			c.erase(c.begin());
    		}
    	}
    }
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
