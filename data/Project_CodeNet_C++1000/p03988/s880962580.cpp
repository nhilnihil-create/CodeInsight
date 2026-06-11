#include<bits/stdc++.h>
using namespace std;
int n,x,v[105];
void GG(){
	puts("Impossible");
	exit(0);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		v[x]++;
	}
	int l=n;
	while (!v[l])l--;
	int m=l+1>>1;
	if (l==1&&n>2)GG();
	if ((l&1)&&(v[m]^2))GG();
	if (!(l&1)&&(v[m]^1)&&n>2)GG();
	for (int i=m+1;i<=l;i++)
		if (v[i]<2)GG();
	for (int i=1;i<m;i++)
		if (v[i])GG();
	puts("Possible");	
}