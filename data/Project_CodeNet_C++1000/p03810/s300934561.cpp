#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5;
int n,a[maxn];
int gcd(int a,int b){return (b==0)?a:gcd(b,a%b);}
bool solve(){
	int id,g,cnt[2]={0,0};
	for(int i=1;i<=n;i++){
	    if(a[i]&1){id=i;cnt[1]++;}
	    else{cnt[0]++;}
	}
	if(cnt[0]%2==1){return true;}
	if(cnt[0]%2==0){
		if(cnt[1]!=1){return false;}
		if(a[id]==1){return false;}
		a[id]--;g=a[1];
		for(int i=2;i<=n;i++){g=gcd(a[i],g);}
		for(int i=1;i<=n;i++){a[i]/=g;}
		return !solve();
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);}
	if(solve()){printf("First\n");}
	else{printf("Second\n");}
	return 0;
}