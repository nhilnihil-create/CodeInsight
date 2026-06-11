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
	int  n;
    string str; 
    cin >> n >> str ;  
    int f=0,s=0;
    for (int i=0;i<sz(str);i++){
    	if (str[i]=='(') s++;
    	else {
    		if (s>0) s--;
    		else f++;
    	}
    }
    for (int i=0;i<f;i++) cout << "(" ;
    cout << str ;
	for (int i=0;i<s;i++) cout << ")";
	cout << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
