#include<iostream>
#include<cstdio>
using namespace std;
int n,f[101],p[101],k;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&f[i]);
		k=max(k,f[i]);
		p[f[i]]++;
	}
	if(k%2){
		for(int i=1;i<=k/2;i++){
			if(p[i]){
				printf("Impossible\n");
				return 0;
			}
		}
		if(p[k/2+1]!=2){
			printf("Impossible\n");
			return 0;
		}
		for(int i=k/2+2;i<=k;i++){
			if(p[i]<2){
				printf("Impossible\n");
				return 0;
			}
		}
	}else{
		for(int i=1;i<k/2;i++){
			if(p[i]){
				printf("Impossible\n");
				return 0;
			}
		}
		if(p[k/2]!=1){
			printf("Impossible\n");
			return 0;
		}
		for(int i=k/2+1;i<=k;i++){
			if(p[i]<2){
				printf("Impossible\n");
				return 0;
			}
		}
	}
	printf("Possible\n");
}