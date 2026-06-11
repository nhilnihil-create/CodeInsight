#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n,greater<int>());
	int l=0;
	while(a[l+1]>l+1)l++;
	int x=a[l]-l-1,y=n-1;
	while(a[y]<=l)y--;
	y-=l;
	int f=0;
	if(x%2==1||y%2==1)f=1;
//	printf("%d %d\n",x,y);
	printf(f?"First":"Second");
}