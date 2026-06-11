#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long

using namespace std;

ll ans1,ans2; int a[10];

int main(){
	rep (i,1,7) scanf("%d",&a[i]);
	ans1=4ll*(a[1]/2)+2ll*a[2]+4ll*(a[4]/2)+4ll*(a[5]/2);
	if ((a[1]&1)&&(a[4]&1)&&(a[5]&1)) ans1+=6;
	if (a[1]&&a[4]&&a[5]) ans2=6,a[1]--,a[4]--,a[5]--; else ans2=0;
	ans2+=4ll*(a[1]/2)+2ll*a[2]+4ll*(a[4]/2)+4ll*(a[5]/2);
	cout<<max(ans1,ans2)/2;
	return 0;
}