#include<bits/stdc++.h>
using namespace std;
int a[100002];
inline bool cmp(int x,int y){return x>y;}
int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) if(i+1>a[i+1]){
		for(int j=i+1;a[j]==i;j++) ans^=1;
		ans|=(a[i]-i)&1,printf(ans?"First":"Second");
		return 0;
	}
}