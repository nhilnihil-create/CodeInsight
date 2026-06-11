#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN=1000+10;
int a[MAXN],n,m;
vector<int> ans;

int main()
{
	scanf("%d %d",&n,&m);
	int cnt=0;
	for(int i=1;i<=m;++i) scanf("%d",&a[i]),cnt+=a[i]&1;
	if(cnt>2){printf("Impossible\n");return 0;};
	for(int i=2;i<m;++i) 
		if(a[i]&1) a[1]&1?swap(a[i],a[m]):swap(a[i],a[1]);
	for(int i=1;i<=m;++i) printf("%d ",a[i]);
	if(m==1&&a[1]==1) ans.push_back(1);
	else if(m==1) ans.push_back(a[1]-1),ans.push_back(1);
	else 
	{
		if(a[1]!=1) ans.push_back(a[1]-1);
		for(int i=2;i<m;++i) ans.push_back(a[i]);
		ans.push_back(a[m]+1);
	};
	printf("\n%d\n",ans.size());
	for(int i=0;i<ans.size();++i) printf("%d ",ans[i]);
 	return 0;
}
