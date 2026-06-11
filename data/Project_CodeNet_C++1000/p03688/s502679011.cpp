#include<bits/stdc++.h>
using namespace std;

int n,a[100005];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(a[n]-a[1]>=2) {puts("No");return 0;}
	else {
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			if(a[i]==a[1]) cnt1++;
			else cnt2++;
		}
		if(cnt2==0){
			if(a[1]<=n/2||a[1]==n-1) {printf("Yes\n");return 0;}
			else printf("No\n");
		}
		else{
			if(cnt1<=a[1]&&(cnt1+cnt2/2)>=a[n]) {printf("Yes\n");return 0;}
			else printf("No\n");
		}
	}
	return 0;
}