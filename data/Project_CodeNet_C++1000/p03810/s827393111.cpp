#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100010;
int a[maxn];
int n,num=0,ex=0;
long long sum=0;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
bool pan(){
	int g=0,num=0;sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i]-1;
		if(a[i]&1) num++;
		if(a[i]==1) ex=1;
	}
	if(ex==1) return sum%2;
	if((n-num)&1) return 1;
	if(num==1){
		for(int i=1;i<=n;i++)
		if(a[i]&1) a[i]--;
		for(int i=1;i<=n;i++)
		g=gcd(g,a[i]);
		for(int i=1;i<=n;i++)
		a[i]=a[i]/g;
		return pan()^1;
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	if(pan()) puts("First");
	else puts("Second"); 
	return 0;
}