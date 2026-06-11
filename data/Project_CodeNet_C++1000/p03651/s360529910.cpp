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

ll gcd(ll a,ll b){
	if(a<b){
		swap(a,b);
	}

	while(ll r=(a%b)){
		a = b;
		b = r;
	}
	return b;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	int N=in(),K=in();
	vector<ll> A=vecin<ll>(N);
	REP(i,N){
		if(A[i]==K){
			out("POSSIBLE");
			return 0;
		}
	}
	sort(ALL(A),greater<ll>());

	if(A[0]<K){
		out("IMPOSSIBLE");
		return 0;
	}

	ll G=A[0];
	REP(i,N-1){
		G = gcd(G,A[i+1]);
	}
	out(!(K%G)?"POSSIBLE":"IMPOSSIBLE");
	return 0;
}
