#include<bits/stdc++.h>
using namespace std;
int n,k;
struct node
{
	int val,id;
	inline bool operator<(const node &rhs){return val<rhs.val;}
}a[233333];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].val,a[i].id=i;
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)if(i%2!=a[i].id%2)ans++;
	cout<<ans/2<<endl;
	return 0;
}