#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <functional>
#include <iostream>
#define INF 2000000000LL
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
ll a[100005];
ll fact[100005];
int b[100005];
int c[100005];

int main(void){
	scanf("%d",&n);
	fact[0]=1;
	for(ll i=1;i<=n;i++){
		fact[i]=fact[i-1]*i%MOD;
	}
	int len=0;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(i>0 && a[i]-a[i-1]==1)len++;
		b[i]=len;
		int l=-1,r=n-1;
		while(r-l>1){
			int mid=(l+r)/2;
			int val=2*(i-mid)+1;
			if(a[i]>=val)r=mid;
			else l=mid;
		}
		c[i]=r;
	}
	ll res=1,turn=0,rest=0;
	for(int i=0;i<n;i++){
		if(c[i]<=turn){
			rest++;
		}else{
			while(c[i]>turn){
				turn++;
				res=res*(rest+1)%MOD;
				rest--;
			}
			rest++;
		}
	}
	res=res*fact[rest]%MOD;
	printf("%lld\n",res);
	/*
	b[n]=114514;
	for(int i=0;i<n;i++){
		printf("%d ",b[i]);
	}
	printf("\n");
	ll res=1;
	int emp=a[0];
	int j=0;
	for(int i=0;i<n-1;i++){
		printf("%d %d\n",len,emp);
		int g=upper_bound(b,b+n,emp)-b;
		res=(ll)res*(g-i)%MOD;
		emp=a[i+1];
		printf("%d\n",res);
	}
	printf("%lld\n",res);
	printf("%lld\n",fact[n-1]*12LL%MOD);
	*/
	return 0;
}