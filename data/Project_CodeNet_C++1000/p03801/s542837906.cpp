#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans[120000],one,two;
struct node {int num,at;} sxd[120000];
bool cmp(node a,node b) {return (a.num==b.num)?a.at<b.at:a.num>b.num;}
signed main() {
	cin>>n;
	for(int i=1;i<=n;i++) {cin>>sxd[i].num;sxd[i].at=i;}
	sort(sxd+1,sxd+n+1,cmp);
	one=1,two=2;
	while(two<=n) {
		while(sxd[two].num==sxd[two-1].num) two++;
		ans[sxd[one].at]+=(two-1)*(sxd[one].num-sxd[two].num);
		if(sxd[one].at<sxd[two].at) sxd[one].num=sxd[two].num;
		else one=two;
		two++;
	}
	ans[sxd[one].at]+=sxd[one].num*n;
	for(int i=1;i<=n;i++) {cout<<ans[i];puts("");}
	return 0;	
}