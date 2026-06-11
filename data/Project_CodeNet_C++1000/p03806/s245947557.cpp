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
T in(){ T x; cin >> x; return (x); }
template<typename T=int,typename C=vector<T>>
C vecin(int N){ C x(N);REP(i,N){ x[i]=in<T>(); }return move(x); }

void vout(){ cout << endl; }
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){ cout << ' ' << h;vout(forward<Tail>(t)...); }
void out(){ cout << endl; }
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){ cout << h;vout(forward<Tail>(t)...); }

class Data{
public:
	int A,B,C;
	Data():A(0),B(0),C(0){}
	Data(int a,int b,int c):A(a),B(b),C(c){}
};

template<typename T>
bool chmin(T& a,T b){ if(a>b){ a=b;return true; }return false; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);

	int N=in(),MA=in(),MB=in();
	vector<Data> D(N);
	int SA=0,SB=0;
	REP(i,N){
		D[i].A=in();
		D[i].B=in();
		D[i].C=in();

		SA+=D[i].A;
		SB+=D[i].B;
	}
	
	vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(SA+1,vector<int>(SB+1,1<<30)));
	dp[0][0][0]=0;
	REP(i,N){
		REP(j,SA+1){
			REP(k,SB+1){
				chmin(dp[i+1][j][k],dp[i][j][k]);
				if(j+D[i].A<=SA && k+D[i].B<=SB) chmin(dp[i+1][j+D[i].A][k+D[i].B],dp[i][j][k]+D[i].C);
			}
		}
	}

	int minC=1<<30;
	int VA=MA,VB=MB;
	while(VA<=SA && VB<=SB){
		minC = min(minC,dp[N][VA][VB]);
		VA+=MA;
		VB+=MB;
	}
	
	out(minC>=1<<30 ? -1 : minC);
	return 0;
}
