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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	ll N=in(),W=in();
	vector<pair<ll,ll>> P[4];
	ll w0=-1;
	REP(i,N){
		ll u=in(),v=in();
		if(w0<0) w0=u;
		P[u-w0].emplace_back(u,v);
	}
	REP(i,4){
		sort(ALL(P[i]),PAIRCOMP(second,>));
	}
	int M[4];
	vector<pair<ll,ll>> S[4];
	REP(i,4){
		M[i]=P[i].size();
		S[i].resize(M[i]+1);
		S[i][0]=make_pair(0,0);
	}
	REP(i,4){
		for(int j=0;j<M[i];j++){
			S[i][j+1]= make_pair(S[i][j].first+P[i][j].first,S[i][j].second+P[i][j].second);
		}
	}

	ll ans=0;
	REP(a,M[0]+1){
		REP(b,M[1]+1){
			REP(c,M[2]+1){
				REP(d,M[3]+1){
					ll weight = S[0][a].first+S[1][b].first+S[2][c].first+S[3][d].first;
					ll value = S[0][a].second+S[1][b].second+S[2][c].second+S[3][d].second;
					if(weight<=W){
						ans = max(ans,value);
					}
				}
			}
		}
	}
	
	out(ans);
	return 0;
}
