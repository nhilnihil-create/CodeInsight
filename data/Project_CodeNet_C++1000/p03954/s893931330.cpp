#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+999;

int a[maxn],n;

inline bool check(int k){
    if((a[n-1]<=k&&a[n]<=k)||(a[n]<=k&&a[n+1]<=k))return 1;
    if((a[n-1]>k&&a[n]>k)||(a[n]>k&&a[n+1]>k))return 0;
    for(int i=1;i<n-1;i++){
        if((a[n+i]<=k&&a[n+i+1]<=k)||(a[n-i]<=k&&a[n-i-1]<=k))return 1;
        if((a[n+i]>k&&a[n+i+1]>k)||(a[n-i]>k&&a[n-i-1]>k))return 0;
    }
    return a[1]<=k;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n-1;++i)scanf("%d",&a[i]);
	int l=1,r=2*n-1;
	while(l<r){
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l;
} 