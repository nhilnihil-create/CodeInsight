#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <numeric>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
int INF = 1e9;


int main(){
	ll a,b,x;cin >> a >> b >> x;
	ll ans =b/x - max(a-1,ll(0))/x ;
	if(a == 0) ans += 1;
	cout << ans << endl;
} 
