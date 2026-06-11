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
int n,a[N],x,y;
map<int,int>mp;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a,a+n);
	x=y=-1;
	for(int i=0;i<n;i++){
		if(mp[a[i]]>=2&&a[i]>=x){
			y=x;
			x=a[i];
			mp[a[i]]-=2;
		}
		else if(mp[a[i]]>=2&&a[i]>y){
			y=a[i];
			mp[a[i]]-=2;
		}
	}
	if(x!=-1&&y!=-1) cout<<1LL*x*y<<endl;
	else puts("0");
	return 0;
}