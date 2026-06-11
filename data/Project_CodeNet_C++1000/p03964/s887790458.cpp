/*.....Bismillahir Rahmanir Rahim.....*/
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
#define   ld long double
#define   pb push_back
#define   sz(x)  (int)x.size()
#define   ff first
#define   ss second
#define   pii  pair<int,int> 
#define   pb  push_back
#define   eb  emplace_back
using namespace std;

void solve(){
	int  n,T,A,t,a;
	cin >> n >>T >> A ; 
	//cout << 1 <<" "<< T <<' '<< A<<endl;
	for (int i=1;i<n;i++){
		cin>>t>>a;
		int m;
		T += (t-1);
		A += (a-1);
		m = max(T/t,A/a);
		T = t*m;
		A = a*m;
		//cout << m <<" "<< T <<" "<< A << endl;
	}
	cout << T+A << endl; 
}

signed main()
{
	int  n=1; // cin >> n;
	while (n--) 
	solve();
    return 0;
}
/*
5
3 10
48 17
31 199
231 23
3 2

*/