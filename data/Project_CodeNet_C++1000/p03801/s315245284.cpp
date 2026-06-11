#include<iostream>
#include<algorithm>
using namespace std;
const int N=100005;
struct node
{
	int val,id;
	bool operator<(const node& rhs)const
	{
		if(val==rhs.val)
			return id<rhs.id;
		return val>rhs.val;
	}
}a[N];
long long ans[N];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].val;
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	int id=a[1].id;
	a[n+1].val=0;
	for(int i=1;i<=n;i++)
	{
		ans[id]+=1ll*(a[i].val-a[i+1].val)*i;
		id=min(id,a[i+1].id);
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<endl;
	return 0;
}