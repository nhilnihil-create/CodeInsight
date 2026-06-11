#include<bits/stdc++.h>
using namespace std;
long long n,a,ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a);
		ans+=a;
	}
	if (ans%2==0) printf("YES\n");
	else printf("NO\n");
	return 0;
} 