#include<bits/stdc++.h>
using namespace std;
int n;
int a[20000010];
#define big(x,y,z) a[x]>z&&a[y]>z
#define small(x,y,z) a[x]<=z&&a[y]<=z
bool check(int k){
	 for(int i=0;i<n-1;i++){
	 	int t1=n+i,t2=n+i+1;
	 	int t3=n-i,t4=n-i-1;
        if(big(t1,t2,k)||big(t3,t4,k)) return 0;
        if(small(t1,t2,k)||small(t3,t4,k)) return 1;
    }
    return small(1,1,k);
}
int main(){
	cin>>n;
	for(int i=1;i<=2*n-1;++i){
		scanf("%d",&a[i]);
	}
	int l=0,r=2*n+1;
	int ans;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<ans<<endl;
}