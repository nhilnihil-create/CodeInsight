#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	ll n,c,k;cin>>n>>c>>k;
	vector<ll> t(n);
	for(int i = 0; i < n; i++) {
		cin>>t[i];
	}
	sort(ALL(t));
	ll tmp = t[0] + k;
	ll ans = 1;
	ll res = 0;
	for(int i = 1; i < n; i++) {
		if (ans < c && t[i] <= tmp){
			ans++;
		}
		else{
			res += (ans + c - 1) / c;
			tmp = t[i] + k;
			ans = 1;
		}
	}
	res += (ans + c - 1) / c;
	cout << res << endl;
	return 0;
}