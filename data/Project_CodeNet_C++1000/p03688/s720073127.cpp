#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,_max,a[N];
bool check(int co,int n){
	if(co<0)	return false;
	if(!n)	return true;
	if(!co)	return false;
	if(co*2>n)	return false;
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		_max=max(_max,a[i]);
	}
	for(int i=1;i<=n;i++)
		if(a[i]<_max-1){
			puts("No");
			return 0;
		}
	int k=0;
	for(int i=1;i<=n;i++)
		if(a[i]==_max-1)	++k;
	if(check(_max-k,n-k)||(!k&&_max==n-1))	puts("Yes");
	else	puts("No");
	return 0;
}