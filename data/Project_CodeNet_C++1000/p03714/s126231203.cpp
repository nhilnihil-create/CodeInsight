#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define LOOP(i) while(i--)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto pitr=c.begin();pitr!=c.end();++pitr){cout<<*pitr;if(next(pitr,1)!=c.end())cout<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;

constexpr ll atcoder_mod = 1e9+7;

template<typename T=int>
T in(){T x; cin >> x; return (x);}
template<typename T=int,typename C=vector<T>>
C vecin(int N){C x(N);REP(i,N){x[i]=in<T>();}return move(x);}

void vout(){cout << endl;}
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){cout << ' ' << h;vout(forward<Tail>(t)...);}
void out(){cout << endl;}
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){cout << h;vout(forward<Tail>(t)...);}

class Combination{
	constexpr static int atcoder_mod = 1000000007;
	vector<ll> fac,finv,inv;
public:
	Combination(ll N){
		fac.resize(N+1);
		finv.resize(N+1);
		inv.resize(N+1);
		fac[0] = fac[1] = 1;
		finv[0] = finv[1] = 1;
		inv[1] = 1;
		for(int i=2;i<=N;i++){
			fac[i] = fac[i-1] * i % atcoder_mod;
			inv[i] = atcoder_mod - inv[atcoder_mod%i] * (atcoder_mod/i) % atcoder_mod;
			finv[i] = finv[i-1] * inv[i] % atcoder_mod;
		}
	}
	ll Caluclation(ll n,ll r){
		if(n < r) return 0;
		if (n < 0 || r < 0) return 0;
		return fac[n] * (finv[r] * finv[n-r] % atcoder_mod) % atcoder_mod;
	}
	ll GetFInv(ll i){
		return finv[i];
	}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	int N=in();
	vector<ll> P=vecin<ll>(3*N),C(N+1,0);
	priority_queue<ll> R;
	priority_queue<ll,vector<ll>,greater<ll>> L;
	ll sumL=0,sumR=0;
	REP(i,N){
		sumL += P[i];
		L.emplace(P[i]);
		sumR += P[3*N-1-i];
		R.emplace(P[3*N-1-i]);
	}
	C[N]=sumR;
	REP(i,N){
		auto V=R.top();
		R.pop();
		if(V>P[2*N-1-i]){
			sumR += P[2*N-1-i]-V;
			R.emplace(P[2*N-1-i]);
		}
		else{
			R.emplace(V);
		}
		C[N-1-i] = sumR;
	}
	ll ans=-(1LL<<60);
	REP(i,N+1){
		ans = max(ans,sumL-C[i]);
		auto V=L.top();
		L.pop();
		if(V<P[N+i]){
			sumL += P[N+i]-V;
			L.emplace(P[N+i]);
		}
		else{
			L.emplace(V);
		}
	}

	out(ans);
	return 0;
}