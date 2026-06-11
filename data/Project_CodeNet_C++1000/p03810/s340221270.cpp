#include<iostream>
#include<stdio.h>
#include<string.h>
#define N 120000
using namespace std;
int a[N],n;
long long sum;
int gcd(int x,int y){
	if(x%y==0)return y;
	return gcd(y,x%y);
} 
bool solve(){
	int k=0;
	sum=0;
	for(int i=1;i<=n;i++)sum+=a[i],k+=a[i]&1;
	if((sum-n)&1)return true;
	if(k>1)return false; 
	for(int i=1;i<=n;i++){
		if(a[i]&1){
			if(a[i]==1)return false; 
			a[i]--;
		}
	}
	int o=a[1];
	for(int i=1;i<=n;i++)o=gcd(a[i],o);
	if(o==1)return false;
	for(int i=1;i<=n;i++)a[i]/=o;
	return !solve();
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	bool ans=solve();
	if(ans)printf("First\n");
	else printf("Second\n");
}