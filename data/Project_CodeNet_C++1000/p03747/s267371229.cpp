#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;

const int N=100005;

int n,l,t;
int a[N],x[N],w[N];

int main(){
	int i,j=0;
	scanf("%d%d%d",&n,&l,&t);
	for (i=0;i<n;i++){
		scanf("%d%d",&x[i],&w[i]);
		if (w[i]==1){
			a[i]=(x[i]+t)%l;
			j+=(x[i]+t)/l;
		}
		else{
			a[i]=(x[i]-t)%l;
			j-=(t-x[i])/l;
			if (a[i]<0) a[i]+=l,j--;
		}
		j=(j%n+n)%n;
	}
	sort(a,a+n);
	for (i=j;i<n;i++) printf("%d\n",a[i]);
	for (i=0;i<j;i++) printf("%d\n",a[i]);
	return 0;
} 