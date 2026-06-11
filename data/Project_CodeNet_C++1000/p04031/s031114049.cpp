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
#define  sz(x)  (int)x.size()
#define  ff first
#define  ss second
#define  pii  pair<int,int>
using namespace std;

int  gcd(int a,int b) {
	return  (b==0)? a: gcd(b,a%b);
}
int  sq(int i,int j){
	return ((i-j)*(i-j));
}
	
void solve(){ 
	int  n;  cin >> n ;
	int  a[n] ; 
	int mn=100,mx=-100;
	for (int i=0;i<n;i++){
		cin >> a[i]; 
		mn= min(a[i],mn);
		mx = max(a[i],mx);
	}
	int res=100000000,cur;
	for (int i=mn;i<=mx;i++){
		cur=0;
		for (int j=0;j<n;j++)
			cur += sq(a[j], i);
		res = min(res,cur);
	}
	cout << res << endl ; 
}

signed main() {
	solve();
    return 0;
}
