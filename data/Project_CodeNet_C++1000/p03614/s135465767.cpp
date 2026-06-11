#include<bits/stdc++.h>
using namespace std;

int n, ans;

int main()
{
	scanf("%d",&n);
	int C = 0;
	for(int i=1;i<=n;i++) {
		int T;
		scanf("%d",&T);
		if(i != T) {
			ans += (C+1)/2;
			C = 0;
		}
		else C++;
	}
	printf("%d\n",ans+(C+1)/2);
}
