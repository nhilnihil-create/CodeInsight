#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int n;
long long a[200005], ans = 1e18, sm, ps;
int main(){
	scanf("%d", &n);
	rep(i,n){
    	scanf("%lld", a+i);
    	sm += a[i];
    }
	rep(i,n-1){
    	ps += a[i];
		ans = min(ans, abs(sm - ps*2));
    }
	printf("%lld\n", ans);
}