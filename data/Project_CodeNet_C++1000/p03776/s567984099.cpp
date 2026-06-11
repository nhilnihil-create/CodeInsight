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
		return fac[n] * (finv[r] * finv[n-r]);
	}
	ll GetFInv(ll i){
		return finv[i];
	}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	int N=in(),A=in(),B=in();
	map<ll,ll,greater<ll>> M;
	REP(i,N){
		M[in<ll>()]++;
	}
	double ansA=0;
	ll ansN=0;

	vector<vector<ll>> comb(N+1,vector<ll>(N+1,0));
	comb[0][0]=1;
	for(int i=1;i<=N;i++){
		for(int j=0;j<=N;j++){
			if(j==0) comb[i][j]=1;
			else if(j==i){
				comb[i][j]=1;
				break;
			}
			else{
				comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
			}
		}
	}
	auto comb_calc = [&](int n,int r){
		if(r==0 || r==n) return 1LL;
		return comb[n][r];
	};

	ll v=1,rest=A,sum=0,restV;
	for(auto& x:M){
		if(rest-x.second<0){
			sum += rest*x.first;
			v = comb_calc(x.second,rest);
			restV = x.second;
			break;
		}
		sum += x.second*x.first;
		rest -= x.second;
	}
	ansA = sum/(double)(A);

	if(rest==A){
		for(int i=A;i<=B;i++){
			ansN += comb_calc(restV,i);
		}
	}
	else{
		ansN = comb_calc(restV,rest);
	}
	
	out(ansA);
	out(ansN);
	return 0;
}