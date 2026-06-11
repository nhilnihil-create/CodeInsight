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
int n,a[N],b[N];
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i],b[a[i]]++;
	int ans=0;
	for(int i=0;i<1e5;i++){
		int tmp=b[i];
		if(i-1>=0) tmp+=b[i-1];
		if(i+1<1e5) tmp+=b[i+1];
		ans=max(ans,tmp);
	}
	cout<<ans<<endl;
	return 0;
}