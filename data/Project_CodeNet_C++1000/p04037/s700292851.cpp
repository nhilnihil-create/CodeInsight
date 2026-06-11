#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main(){
	int n,i,j,win=0;cin>>n;
	for(i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	for(i=1;i<=n;++i){
		if(a[i+1]<i+1 && a[i]>=i){
			j=i+1;
			while(a[j]==i) j++,win^=1;
			win|=((a[i]-i)&1);
			if(win) puts("First");
			else puts("Second");
		}
	}
}