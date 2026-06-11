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
	int n,x;cin >> n >> x;
	if(x == 1 || x == 2*n-1) {
		cout << "No" << endl;
		return 0;
	}else cout << "Yes" << endl;

	vector<int> ans(200006,0);
	vector<bool> num(200006,true);
	if(x == 2){
		ans[n-2] = x;
		ans[n-1] = 1;
		num[x] = false;
		num[1] = false;
	}else{
		ans[n-2] = x;
		ans[n-1] = 2*n-1;
		ans[n] = x-1;
		num[x] = false;
		num[2*n-1] = false;
		num[x-1] = false;
		if(n>2) {
			ans[n-3] = x-2;
			num[x-2] = false;
		}
	}
	int ind = 1;
	rep(i,2*n-1){
		if(ans[i]!=0) continue;
		while(!num[ind]) ind++;
		ans[i] = ind;
		num[ind] = false;
	}
	rep(i,2*n-1) cout << ans[i] << endl;


}
