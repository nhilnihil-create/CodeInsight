#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const ll MAX_N=1e9;
int L;
ll pw(ll n,int m){
	ll ret=1;
	while(m){
		if (m&1){
			ret*=n;
		}
		n*=n;
		m>>=1;
	}
	return ret;
}

int main(){
	L=-1;
	REP(k,10){
		cout<<"? 1";
		REP(i,k){
			cout<<0;
		}
		cout<<endl;
		char res;
		cin>>res;
		if (res=='N'){
			L=k;
			break;
		}
	}
	if (L==-1){
		REP(k,10){
			cout<<"? 2";
			REP(i,k){
				cout<<0;
			}
			cout<<endl;
			char r;
			cin>>r;
			if (r=='Y'){
				cout<<"! 1";
				REP(i,k){
					cout<<0;
				}
				cout<<endl;
				break;
			}
		}
	}else{
		ll lb=pw(10,L-1)-1,ub=pw(10,L)-1;
		while(ub-lb>1){
			ll mid=(lb+ub)>>1;
			cout<<"? "<<mid<<"0"<<endl;
			char r;
			cin>>r;
			if (r=='Y'){
				ub=mid;
			}else{
				lb=mid;
			}
		}
		cout<<"! "<<ub<<endl;
	}
	return 0;
}