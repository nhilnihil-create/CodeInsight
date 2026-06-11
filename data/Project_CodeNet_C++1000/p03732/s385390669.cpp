#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//Write From this Line

int main()
{
	ll N, W;
	cin >> N >> W;
	vector<ll> w(N), v(N);
	rep(i,N) cin >> w[i] >> v[i];

	map<ll,ll> mp;
	vector<ll> v0(0), v1(0), v2(0), v3(0);
	rep(i,N){
		if(w[i] - w[0] == 0){ mp[0]++; v0.push_back(v[i]);}
		if(w[i] - w[0] == 1){ mp[1]++; v1.push_back(v[i]);}
		if(w[i] - w[0] == 2){ mp[2]++; v2.push_back(v[i]);}
		if(w[i] - w[0] == 3){ mp[3]++; v3.push_back(v[i]);}
	}
	SORT(v0); SORT(v1); SORT(v2); SORT(v3);
	rSORT(v0); rSORT(v1); rSORT(v2); rSORT(v3);
	vector<ll> V0(v0.size()+1,0);
	vector<ll> V1(v1.size()+1,0);
	vector<ll> V2(v2.size()+1,0);
	vector<ll> V3(v3.size()+1,0);
	For(i,1,V0.size()) V0[i] = V0[i-1] + v0[i-1];
	For(i,1,V1.size()) V1[i] = V1[i-1] + v1[i-1];
	For(i,1,V2.size()) V2[i] = V2[i-1] + v2[i-1];
	For(i,1,V3.size()) V3[i] = V3[i-1] + v3[i-1];

	ll ans = 0;
	//debug(mp[0]);
	//debug(v0.size());
	//debug(V0.size());
	//debug(mp[0]);
	rep(a,V0.size()){
		rep(b,V1.size()){
			rep(c,V2.size()){
				rep(d,V3.size()){
					ll weight = (a+b+c+d) *w[0];
					weight += b + 2*c + 3*d;
					if(weight <= W){
						ll now = V0[a] + V1[b] + V2[c] + V3[d];
						chmax(ans,now);
					}
				}
			}
		}
	}
	cout << ans << endl;
}
