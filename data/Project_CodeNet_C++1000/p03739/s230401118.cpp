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
int n,a[N]; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	ll s=0,ans=1e18,p=a[1];
	if(a[1]<=0){
	s+=abs(a[1])+1;
	p=1;
	}
	for(int i=2;i<=n;i++){
		if(i%2==0){
			if(p+a[i]>=0){
				s+=abs(a[i]+p)+1;
				p=-1;
			}
			else p+=a[i];
		}
		else {
			if(p+a[i]<=0){
				s+=abs(a[i]+p)+1;
				p=1;
			}
			else p+=a[i];
		}
	}
	ans=min(ans,s),s=0,p=a[1];
	if(a[1]>=0){
	s+=abs(a[1])+1;
	p=-1;	
	}
	for(int i=2;i<=n;i++){
		if(i&1){
			if(p+a[i]>=0){
				s+=abs(a[i]+p)+1;
				p=-1;
			}
			else p+=a[i];
		}
		else {
			if(p+a[i]<=0){
				s+=abs(a[i]+p)+1;
				p=1;
			}
			else p+=a[i];
		}
	}
	printf("%lld\n",min(ans,s));
	return 0;
}