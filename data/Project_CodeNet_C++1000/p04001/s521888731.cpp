#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
#define Graph vector<vector<ll>>
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

ll ans=0;

ll mypow(ll a,ll b){
	ll num=1;
	while(b!=0){
		b--;
		num*=a;
	}
	return num;
}

ll keta(ll a){
	ll num=0;
	while(a!=0){
		a/=10;
		num++;
	}
	return num;
}

void dfs(ll s,ll num,vector<bool> &BO){
	if(num==keta(s)){
		ll prt=0,prtsum=0;
		BO[keta(s)-1]=true;//sentinel
		
		rep(i,keta(s)){
			if(BO[i]){
				prt=prt*10+(s/mypow(10,keta(s)-i-1))%10;
				prtsum+=prt;
				prt=0;
			}else{
				prt=prt*10+(s/mypow(10,keta(s)-i-1))%10;
			}
		}

		ans+=prtsum;
		return;
	}

	BO[num]=true;
	dfs(s,num+1,BO);

	BO[num]=false;
	dfs(s,num+1,BO);

	return;
} 

int main(){
	ll s;cin>>s;
	vector<bool> BO(keta(s),false);

	dfs(s,0,BO);

	cout<<ans/2<<endl;
	return 0;
}