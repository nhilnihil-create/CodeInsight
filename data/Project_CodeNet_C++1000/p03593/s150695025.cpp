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

	ll H=in(),W=in();
	map<char,ll> M;
	REP(i,H){
		string S=in<string>();
		REP(j,W){
			M[S[j]]++;
		}
	}

	ll one=0,two=0,four=(H/2)*(W/2);
	if((H%2) && (W%2)){
		one=1,two=H/2+W/2;
		four=(H/2)*(W/2);
	}
	else if((H%2) || (W%2)){
		two=(H%2)?W/2:H/2;
		four=(H/2)*(W/2);
	}
	
	for(auto& x:M){
		if((x.second%4)==1 || (x.second%4)==3){
			x.second--;
			one--;
		}
	}
	if(one){
		out("No");
		return 0;
	}

	for(auto& x:M){
		if((x.second%4)==2){
			x.second-=2;
			two--;
		}
	}
	if(two){
		if(two>0 && !(two%2)){
			for(auto& x:M){
				while(two>0 && x.second){
					x.second-=4;
					two-=2;
				}
				if(!two) break;
			}
		}
		else{
			out("No");
			return 0;
		}
		
	}

	for(auto& x:M){
		while(x.second){
			x.second-=4;
			four--;
		}
	}

	if(four){
		out("No");
		return 0;
	}
	out("Yes");
	return 0;
}
