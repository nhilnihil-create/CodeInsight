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
ll  LINF = 1e18;

int main(){
	ll n,l;cin >> n >> l;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	int ind = -1;
	rep(i,n-1) if(a[i]+a[i+1]>=l) ind = i;
	if(ind == -1) {
		cout << "Impossible" << endl;
		return 0;
	}
	cout << "Possible" << endl;
	ind++;
	for(int i = 1;i < ind;i++){
		cout << i << endl;
	}
	for(int i = n-1;i >= ind;i--) cout << i << endl;
	
} 
