#include "bits/stdc++.h"

#define REP(i,num) for(ll i=0;i<(num);++i)
#define FOR(i,c,num) for(ll (i)=(c);(i)<(num);++(i))
#define LOOP(i) while(i--)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto pitr=c.begin();pitr!=c.end();++pitr){cout<<*pitr;if(next(pitr,1)!=c.end())cout<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;

constexpr ll atcoder_mod = 1e9+7;

template<typename T=ll>
T in(){T x; cin >> x; return (x);}
template<typename T=ll,typename C=vector<T>>
C vecin(int N){C x(N);REP(i,N){x[i]=in<T>();}return move(x);}

void vout(){cout << endl;}
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){cout << ' ' << h;vout(forward<Tail>(t)...);}
void out(){cout << endl;}
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){cout << h;vout(forward<Tail>(t)...);}

template<typename T>
bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<typename T>
bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	auto N=in(),A=in(),B=in();
	vll V=vecin(N);
	sort(ALL(V),greater<ll>());
	
	map<ll,ll> C;
	REP(i,N){
		C[V[i]]++;
	}

	ll maxS=0,maxN=1;
	vll L;
	FOR(i,A,B+1){
		ll S = accumulate(V.begin(),V.begin()+i,0ll);
		if(i*maxS<S*maxN){
			L.clear();
			maxS = S;
			maxN = i;
			L.push_back(i);
		}
		else if(i*maxS==S*maxN){
			L.push_back(i);
		}
	}

	out(maxS/(double)maxN);

	vvll comb(51,vll(51,0));
	comb[0][0]=1;
	REP(i,50){
		REP(j,50){
			comb[i+1][j]+=comb[i][j];
			comb[i+1][j+1]+=comb[i][j];
		}
	}
	ll S=0;
 	for(auto& x:L){
		ll X=x,index=0;
		while(X){
			if(C[V[index]]>=X){
				S += comb[C[V[index]]][X];
				X=0;
			}
			else{
				X -= C[V[index]];
			}
			index++;
		}
	}
	out(S);
	return 0;
}
