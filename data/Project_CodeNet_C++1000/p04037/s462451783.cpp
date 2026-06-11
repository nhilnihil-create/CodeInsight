#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100005;

int a[N],n;
bool sg;

inline void solve(){
	for(int i=1;i<=n;i++) if(i+1>a[i+1]){
		for(int j=i+1;a[j]==i;j++) sg^=1;
		sg|=(a[i]-i)&1,puts(sg?"First":"Second");
		break;
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	sort(a+1,a+n+1),reverse(a+1,a+n+1);
	
	solve();
	
	return 0;
}