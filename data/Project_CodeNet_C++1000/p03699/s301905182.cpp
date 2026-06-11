#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int a[N];
int main(){
	int n,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i],s+=a[i];
	}
	int ans=0;
	if(s%10){
		cout<<s<<endl;
	}
	else {
		for(int i=1;i<=n;i++){
			if((s-a[i])%10) ans=max(ans,s-a[i]); 
		}
		cout<<ans<<endl;
	}
	return 0;
}