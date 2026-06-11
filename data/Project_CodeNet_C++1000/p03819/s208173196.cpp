#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,m;
pair<int,int> p[N];
struct bit{
	int a[N];
	void add(int p,int d){
		for (;p<=n;p+=p&-p) a[p]+=d;
	}
	int query(int p){
		int ans=0;
		for (;p;p-=p&-p) ans+=a[p];
		return ans;
	}
}T;
int main()
{
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&p[i].first,&p[i].second);
		p[i].first=p[i].second-p[i].first;
	}
	sort(p+1,p+m+1);
	for (int i=1,j=1;i<=n;i++){
		for (;j<=m&&p[j].first<i;T.add(p[j].second+1,-1),T.add(p[j].second-p[j].first,1),j++);
		int ans=m-j+1;
		for (int k=i;k<=n;k+=i) ans+=T.query(k);
		printf("%d\n",ans);
	}
	return 0;
}