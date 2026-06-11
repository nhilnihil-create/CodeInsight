#include "bits/stdc++.h"

#define REP(i,num) for(ll i=0;i<(num);++i)
#define LOOP(i) while(i--)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto pitr=c.begin();pitr!=c.end();++pitr){cout<<*pitr;if(next(pitr,1)!=c.end())cout<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;

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

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	string S=in<string>();
	vector<vector<int>> P(26);
	int N=S.size();
	REP(i,N){
		P[S[i]-'a'].push_back(i);
	}

	int minV=1<<30;
	REP(i,26){
		if(P[i].empty()) continue;
		
		int maxU=0,left=1<<30;
		for(int j=0,ej=P[i].size();j<ej;j++){
			int right = min(left,(N-P[i][ej-1-j])-1);
			left = P[i][ej-1-j];
			if(ej-1-j>0){
				left = min(left,P[i][ej-1-j]-P[i][ej-2-j]-1);
			}
			maxU = max(maxU,max(left,right));
		}
		minV=min(minV,maxU);
	}
	out(minV);
	return 0;
}
