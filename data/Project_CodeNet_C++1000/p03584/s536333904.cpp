#include<bits/stdc++.h>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long int ll;
const ll MOD=1000000007;
const ll INF=1000000010;
const ll LINF=4000000000000000010LL;
const int MAX=310;
const double EPS=1e-9;
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
int a[100010],b[100010];
int main(){
	ll n,k;cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	bitset<31> bk(k);
	ll ans=0;
	for(int i=0;i<n;i++){
		bitset<31> ba(a[i]);
		bool f=true;
		for(int j=0;j<=30;j++){
			if((!bk[j]&1)&&(ba[j]&1)){
				f=false;
				break;
			}
		}
		if(f){
			ans+=b[i];
		}
	}
	for(int i=31;i>=0;i--){
		bitset<31> bit=bk;
		if(!bk[i])continue;
		bit[i]=0;
		for(int j=i-1;j>=0;j--){
			bit.set(j);
		}
		ll co=0;
		for(int j=0;j<n;j++){
			bitset<31> ba(a[j]);
			bool f=true;
			for(int k=0;k<=30;k++){
				if((!bit[k]&1)&&(ba[k]&1)){
					f=false;
					break;
				}
			}
			if(f){
				co+=b[j];
			}
		}
		ans=max(ans,co);
	}
	cout<<ans<<endl;
}
