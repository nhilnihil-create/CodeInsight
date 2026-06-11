#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int n,a,b,h[N];

bool check(int mid){
	int ret=mid;
	for(int i=0;i<n&&ret>=0;++i)
		if(h[i]>1ll*mid*b)ret-=(h[i]-mid*b-1)/(a-b)+1;
	return ret>=0;
}

int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=0;i<n;++i)scanf("%d",h+i);
	int l=1,r=1000000000;
	while(l<r){
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",r);
	return 0;
}
