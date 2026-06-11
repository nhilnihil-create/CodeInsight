//解説の別解
// 左がxとすると右はsum-xなので
// 最小のabs(sum-2x)をみつける
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

ll gcd(ll a,ll b){
    if(a<b) swap(a,b);
    bool have_mod =true;
    while(have_mod){
        ll mod = a % b;
        if(mod == 0 ) have_mod = false;
        a = b;
        b = mod;
    }
    return a;
}

int main(){
	int n;
	cin >> n;
	vector<ll> t(n);
	rep(i,n) cin >> t[i];
	ll num = t[0];
	for(int i=1;i<n;i++){
		num = t[i]/gcd(num,t[i])*num;
	}
	cout << num << endl;
	return 0;
}