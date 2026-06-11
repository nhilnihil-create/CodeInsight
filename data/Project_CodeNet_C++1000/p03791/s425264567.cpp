#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <cstdio>
#include <utility>
#include <bitset>
#include <complex>
#include <stack>
#include <tuple>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const ll INF = 1e7;
const ll MOD = (1e9)+7;
int main(){
	ll N;
	cin >> N;
	vector<ll> x(N);
	for(int i=0;i<N;i++)
		cin >> x[i];
	ll ans = 1;
	ll now = 1;
	ll num = 0;
	for(ll i=0;i<N;i++){
		if(x[i]>=now){
			now+=2;
			num++;
		}else{
			ans=(ans*(num+1))%MOD;
		}
	}
	for(ll i=1;i<=num;i++)
		ans=(ans*i)%MOD;
	cout << ans << endl;
	return 0;
}
