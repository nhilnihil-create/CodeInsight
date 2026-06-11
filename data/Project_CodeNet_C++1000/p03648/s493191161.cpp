#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second

using namespace :: std;

const ll maxn=51;
const ll mod=1e9+7;
const ll inf=1e9+500;

ll sek[maxn];
int main(){
	ll k;
	cin>>k;
	ll kk=k;
	if(kk%50!=0){
		kk+=50;
	}
	kk=(kk/50)*50;

	for(ll i=0;i<50;i++){
		sek[i]=49+kk/50;
	}
	while(kk>k){
		ll maxx=0;
		ll kimax=0;
		for(ll i=0;i<50;i++){
			if(sek[i]>maxx){
				maxx=sek[i];
				kimax=i;
			}
		}
		sek[kimax]-=51;
		for(ll i=0;i<50;i++){
			sek[i]++;
		}			
		kk--;
	}
	cout<<50<<endl;
	for(ll i=0;i<50;i++){
		cout<<sek[i]<<' ';
	}


}
