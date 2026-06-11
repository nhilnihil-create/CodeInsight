#include<bits/stdc++.h>
using namespace std;
int n,x,r,l,t[105];
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		t[x]++,r=max(r,x);
	}
	l=r+1>>1;
	for(int i=l+1;i<=r;i++){
		if(t[i]<2){
			printf("Impossible");
			return 0;
		}
	}
	if(r&1){
		if(t[l]<2){
			printf("Impossible");
			return 0;
		}
		t[l]-=2;
	} 
	else {
		if(t[l]<1){
			printf("Impossible");
			return 0;
		}
		t[l]-=1;
	}
	for(int i=1;i<=l;i++)
		if(t[i]){
			printf("Impossible");
			return 0;
		}
	printf("Possible");
}