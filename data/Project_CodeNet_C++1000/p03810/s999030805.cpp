#include<bits/stdc++.h>
using namespace std;
int n,x,a[100005];
int solve(int a[]){
	int cnt=0;
	for (int i=1;i<=n;i++)
		if (a[i]%2==0)cnt++;
	if (cnt&1)return 1;
	if (n==1)return 0;
	if (cnt!=n-1)return 0;
	for (int i=1;i<=n;i++)
		if (a[i]&1){
			if (a[i]==1)return 0;
			a[i]--;
		}
	int k=0;
	for (int i=1;i<=n;i++)k=__gcd(k,a[i]);
	for (int i=1;i<=n;i++)a[i]/=k;
	return !solve(a);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	if (solve(a))puts("First");
	else puts("Second");
}