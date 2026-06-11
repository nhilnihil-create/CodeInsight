#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,a[800000];
signed main(){
	cin>>n>>m;
	while(m--){
		int x,y;scanf("%lld%lld",&x,&y);
		a[x]^=1,a[y]^=1;
	}
	for(int i=0;i<800000;i++) if(a[i]) {
		puts("NO");return 0;
	}
	
	puts("YES");
	return 0;
}