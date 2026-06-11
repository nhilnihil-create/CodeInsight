#include<stdio.h>
#include<algorithm>
using namespace std;
int x[110000];
int p[110000];
int t[110000];
int s[110000];
int tmp[110000];
int r[110000];
long long sum[110000];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",x+i);
	int b;
	long long c;
	scanf("%d%lld",&b,&c);
	for(int i=0;i<b;i++){
		scanf("%d",p+i);p[i]--;
	}
	for(int i=0;i<=a;i++)t[i]=i;
	for(int i=0;i<b;i++){
		swap(t[p[i]],t[p[i]+1]);
	}
	for(int i=0;i<=a;i++)s[t[i]]=i;
	for(int i=0;i<=a;i++)r[i]=i;
	while(c){
		if(c%2){
			for(int i=0;i<=a;i++)tmp[i]=s[r[i]];
			for(int i=0;i<=a;i++)r[i]=tmp[i];
		}
		c/=2;
		for(int i=0;i<=a;i++)tmp[i]=s[s[i]];
		for(int i=0;i<=a;i++)s[i]=tmp[i];
	}
	for(int i=0;i<a;i++){
		sum[r[i]]+=x[i];
		sum[r[i+1]]-=x[i];
	}
	for(int i=0;i<a;i++){
		if(i)sum[i]+=sum[i-1];
		printf("%lld\n",sum[i]);
	}
}