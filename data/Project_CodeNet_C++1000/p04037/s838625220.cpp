#include<bits/stdc++.h>
#define N 100100
using namespace std;
int a[N],n,sg=1;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i>=a[i+1]){
			for(int j=i+1;j<=n&&a[j]==i;j++) sg^=1;
			sg&=(a[i]-i+1);
			printf("%s\n",sg?"Second":"First");
			return 0;
		}
	}
}