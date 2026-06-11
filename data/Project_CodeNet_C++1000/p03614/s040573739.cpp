#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	int res=0;
	for(int i=1;i<=n;++i)
		if(a[i]==i)swap(a[i],a[i+1]),res++;
	cout<<res;
	return 0;
}