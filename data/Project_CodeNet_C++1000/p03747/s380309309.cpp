#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,l,t,w,x,pos,a[100010];
int main(){
	scanf("%lld%lld%lld",&n,&l,&t);
	for(i=0;i<n;i++){
		scanf("%lld%lld",&x,&w);
		if(w==1){
			a[i]=(x+t)%l;
			pos+=(x+t)/l;
		}
		 else{
		 	a[i]=(x-t)%l;
		 	pos+=(x-t)/l;
		 	if(a[i]<0){
		 		pos--;a[i]+=l;
			 }
		 }
	}
	sort(a,a+n);
	pos=(pos%n+n)%n;
	for(i=pos;i<n;i++)printf("%lld\n",a[i]);
	for(i=0;i<pos;i++)printf("%lld\n",a[i]);
}