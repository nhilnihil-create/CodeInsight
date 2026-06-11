#include<bits/stdc++.h>
using namespace std;
int l,r,mid,n,a[200005],b[200005],c[200005];
bool check(int t){
	int sum=10000000,z=-1,x,y=-1,num1=0,num2=0;
	for(int i=1; i<=n*2-1; i++){
		if(a[i]<c[t]){
			x=0;
			num1++;
		}
		else{
			x=1;
			num2++;
		}
		if((x==y)&&(min(abs(i-n),abs((i-1)-n))<sum)){
			sum=min(abs(i-n),abs((i-1)-n));
			z=x;
		}
		y=x;
	}
	if(z==-1){
		if(num1>num2)z=0;
		if(num2>num1)z=1;
	}
	if(z==1)return(true);
	else return(false);
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n*2-1; i++){
		scanf("%d",&a[i]);
		c[i]=a[i];
	}
	sort(c+1,c+n*2);
	l=1; r=n*2-1;
	while(l<r){
		mid=(l+r+1)/2;
		if(check(mid)==true)l=mid;
		else r=mid-1;
	}
	printf("%d",c[r]);
}