#include<bits/stdc++.h>

using namespace std;

int n,a[120000];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",a+i);
	sort(a+1,a+n+1,greater<int>());
	for (int i=1;i<=n;++i)
		if (i==n||i+1>a[i+1]){
			int t1=0,t2=0;
			for (int j=i+1;j<=n&&a[j]==i;++j) t1^=1;
			t2=(a[i]-i)&1;
			puts(t1|t2?"First":"Second");
			return 0;
		}
	
	return 0;
}
			