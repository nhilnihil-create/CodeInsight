#include<bits/stdc++.h>
const int MN=200000+5;
using namespace std;
typedef long long ll;
template<typename T>inline T IN(T&in){
	in=0;char c=getchar();int f=1;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))in=in*10+c-'0',c=getchar();
	return in*=f;
}
int n;
int a[MN];
int check(int x){
	for(int i=0;i<n;++i){
		if(((a[n+i]>=x)&&(a[n+i+1]>=x))||((a[n-i]>=x)&&(a[n-i-1]>=x)))return 1;
		if(((a[n+i]<x)&&(a[n+i+1]<x))||((a[n-i]<x)&&(a[n-i-1]<x)))return 0;
	}
	return a[1]>=x;
}
void input(){
	IN(n);
	for(int i=1;i<=2*n-1;++i)a[0]=max(a[0],IN(a[i]));
	int l=1,r=a[0]+1;
	while(l<r){
		int mid=l+r>>1;
		if(check(mid))l=mid+1;
		else r=mid;
	}
	printf("%d\n",l-1);
}
int main(){
	
	input();
	return 0;
}