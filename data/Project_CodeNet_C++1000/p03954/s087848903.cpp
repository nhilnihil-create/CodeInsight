#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e5;
ll n,m,w,a[maxn],b[maxn],d[maxn],c[maxn],k,depth;
bool check()
{
	int mid=(n+1)/2;
	if((b[mid]==1&&b[mid+1]==1)||(b[mid]==1&&b[mid-1]==1))return 1;
	if((b[mid]==0&&b[mid+1]==0)||(b[mid]==0&&b[mid-1]==0))return 0;
	for(int i=1;i<=(n-1)/2;i++){
		if(b[mid+i]==b[mid+i-1])return b[mid+i];
		if(b[mid-i]==b[mid-i+1])return b[mid-i];
	}
	if(depth%2==1)return b[mid];
	else return (b[mid]^1);
}
int main(){
	ll r,l=1;
	scanf("%lld",&depth);n=depth*2-1;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	r=n;ll mid = l+r>>1;
	while(l <= r)
    {
    	mid=l+r>>1;
    	for(int i=1;i<=n;i++)
    		if(a[i]>=mid)b[i]=1;
    		else b[i]=0;
        if(!check())
            r=mid-1; 
        else
            l=mid+1;
    }
    printf("%lld\n",l-1);
}