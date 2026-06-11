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

	auto N=in(),W=in();
	vvll V(4);

	ll w=in(),v=in();
	V[0].push_back(v);
	REP(i,N-1){
		ll x=in();
		V[x-w].push_back(in());
	}
	REP(i,4) sort(ALL(V[i]),greater<ll>());

	ll maxV=0;
	for(ll a=0,ea=V[0].size(),sa=0;a<=ea;a++){
		for(ll b=0,eb=V[1].size(),sb=0;b<=eb;b++){
			for(ll c=0,ec=V[2].size(),sc=0;c<=ec;c++){
				for(ll d=0,ed=V[3].size(),sd=0;d<=ed;d++){
					if((a*w+b*(w+1ll)+c*(w+2ll)+d*(w+3ll))<=W){
						maxV = max(maxV,sa+sb+sc+sd);
					}
					if(d<ed) sd+=V[3][d];
				}
				if(c<ec) sc+=V[2][c];
			}
			if(b<eb) sb+=V[1][b];
		}
		if(a<ea) sa+=V[0][a];
	}

	out(maxV);
	return 0;
}
