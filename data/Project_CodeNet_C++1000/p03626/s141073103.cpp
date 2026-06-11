#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int n;
string a[2];
map<int,int>mp;
int main(){
	cin>>n;
	for(int i=0;i<2;i++)
		cin>>a[i];
	int j=0,pre=0;
	ll ans=1;
	if(a[0][0]==a[1][0]) ans=3,j=1;
	else ans=6,j=2,pre=1;
	for(;j<n;){
		if(a[0][j]==a[1][j]){
			if(!pre) ans=ans*2%mod;
			j++;
			pre=0;
		} 
		else {
			if(!pre) ans=ans*2%mod;
			else ans=ans*3%mod;
			j+=2;
			pre=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}