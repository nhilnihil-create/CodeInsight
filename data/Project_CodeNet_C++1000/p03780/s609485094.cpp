#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int a[N],n,k;
bitset<N>s; 
bool check(int x){
	if(a[x]>=k) return true;
	s.reset();s[0]=1;
	for(int i=1;i<=n;i++) if(i!=x) s|=s<<a[i];
	for(int i=k-1;i>=k-a[x];i--) if(s[i]) return true;
	return false; 
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int l=1,r=n+1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d",l-1);
	return 0;
}