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
	int n;cin >> n;
	ll x=1,y=1;
	rep(i,n){
		ll t,a;cin >> t >> a;
		ll mult = max((x+t-1)/t,(y+a-1)/a);
		x = mult*t;
		y = mult*a;
	}
	cout << x+y << endl;

} 
