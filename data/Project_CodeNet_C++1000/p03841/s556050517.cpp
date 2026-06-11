#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#define inf 2147483647
#define eps 1e-9
using namespace std;
typedef long long ll;
int n,N,cnt=0,s[501],num[501],tot[501],a[250001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		a[num[i]]=i;
		tot[i]=i-1;
	}
	N=n*n;
	for(int i=1;i<=N;i++){
		if(a[i])s[++cnt]=a[i];
	}
	for(int i=1;i<=N;i++){
		if(a[i])continue;
		for(int j=1;j<=n;j++){
			if(!tot[s[j]])continue;
			a[i]=s[j];
			tot[s[j]]--;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		tot[i]=n-i;
	}
	for(int i=N;i;i--){
		if(a[i])continue;
		for(int j=n;j;j--){
			if(!tot[s[j]])continue;
			a[i]=s[j];
			tot[s[j]]--;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		int tmp=0;
		for(int j=1;j<=N;j++){
			if(a[j]==i)tmp++;
			if(tmp==i){
				if(j!=num[i])return puts("No"),0;
				break;
			}
		}
	}
	puts("Yes");
	for(int i=1;i<=N;i++)printf("%d ",a[i]);
	return 0;
}