#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for (int i=1;i<=n;i++)
		if (a[i+1]<i+1){
			int j=i;
			while (j<n&&a[j+1]==i)
				j++;
			int f1=(j-i)&1,f2=(a[i]-i)&1;
			puts(f1||f2?"First":"Second");
			return 0;
		}
	return 0;
}