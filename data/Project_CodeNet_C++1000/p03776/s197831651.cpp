#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;

ll com[51][51];
void init(){
	com[0][0] = 1;
	for(int i = 0;i <= 49;i++){
		for(int j = 0;j <= i;j++){
			com[i+1][j] += com[i][j];
			com[i+1][j+1] += com[i][j];
		}
	}
}

ll comb(ll n,ll k){
	if(k > n)return 0;
	return com[n][k];
}
int main(){
	init();
	int n,a,b;
	cin >> n >> a >> b;
	vector<ll> v(n);

	for(int i = 0;i < n;i++){
		cin >> v[i];
	}
	sort(v.begin(),v.end(),greater<ll>());

	ll mn = v[a-1];
	ll mn_cnt = 0;
	ll sum = 0;
	for(int i = 0;i < a;i++){
		sum += v[i];
		if(v[i] == mn)mn_cnt++;
	}

	double ave = (double)sum/a;
	printf("%lf\n",ave);

	if(v[0] == mn){
		ll cnt = 0;
		for(int i = 0;i < n;i++){
			if(v[i] == mn)cnt++;
		}
		ll ans = 0;
		for(ll i = a;i <= b;i++){
			ans += comb(cnt,i);
		}

		cout << ans << endl;
	}
	else{
		ll cnt = 0;
		for(int i = 0;i < n;i++){
			if(v[i] == mn)cnt++;
		}
		cout << comb(cnt,mn_cnt) << endl;
	}
}
