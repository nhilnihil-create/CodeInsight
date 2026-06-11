#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) (ll)((x).size())
#define pb push_back
#define mp make_pair 
#define bg begin()
#define ed end()
#define all(x) (x).bg,(x).ed
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep1(i,n) for(ll i=1;i<=(n);i++)

int main(){
	ll N; cin>>N;
	string s; cin>>s;

	vector<ll> animal(N); // 0:- 1:S(本) 2:W(噓)
	ll x[4]={1,2,1,2},y[4]={1,1,2,2};
	rep(k,4){
		rep(j,N) animal[j]=0;
		animal[0]=x[k];
		animal[1]=y[k];

		//調査
		rep1(i,N-2){
			if((s[i]=='o' && animal[i]==1) || (s[i]=='x' && animal[i]==2)){
				animal[i+1]=animal[i-1];
			}
			else{
				animal[i+1]=((animal[i-1]-1)^1)+1;
			}
		}

		// 0とN-1の証言正しいか
		// 0
		if((animal[0]==1 && s[0]=='o') || (animal[0]==2 && s[0]=='x')){
			if(animal[1]!=animal[N-1]) continue;
		}
		else{
			if(animal[1]==animal[N-1]) continue;
		}

		// N-1
		if((animal[N-1]==1 && s[N-1]=='o') || (animal[N-1]==2 && s[N-1]=='x')){
			if(animal[0]!=animal[N-2]) continue;
		}
		else{
			if(animal[0]==animal[N-2]) continue;
		}

		rep(i,N){
			if(animal[i]==1) cout<<"S";
			else cout<<"W";
		}
		return 0;
	}
	cout<<-1;
}