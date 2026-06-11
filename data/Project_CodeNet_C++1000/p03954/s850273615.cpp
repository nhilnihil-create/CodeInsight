#include<bits/stdc++.h>
#define N 2000010
using namespace std;
int n,a[N];
int sm(int x,int y,int z){
	return a[x]<=z&&a[y]<=z;
}
int bd(int x,int y,int z){
	return a[x]>z&&a[y]>z;
}
int ck(int x){
	for(int i=0;i<n-1;i++){
		if(bd(n+i,n+i+1,x)||bd(n-i,n-i-1,x))return 0;
		if(sm(n+i,n+i+1,x)||sm(n-i,n-i-1,x))return 1;
	}
	return sm(1,1,x);
}
int main(){
	cin>>n;
	for(int i=1;i<2*n;i++)cin>>a[i];
	int l=1,r=1e7;
	while(l<r){
		int md=(l+r)/2;
		if(ck(md))r=md;
		else l=md+1;
	}
	cout<<r;
}