#include<cstdio>
#include<vector>
using namespace std;
vector<int> ans; 
int main()
{
	long long n;int i,j;
	scanf("%lld",&n);++n;
	for(i=50;i--;)if(n&(1LL<<i))break;
	for(j=1;j<=i;++j)ans.push_back(j);
	for(j=1;j<=i;++j)ans.push_back(j);
	for(j=i;j--;)if(n&(1LL<<j))ans.insert(ans.begin()+i,50+j);
	for(j=0;j<i;++j)if(n&(1LL<<j))ans.insert(ans.begin()+i-j,50+j);
	printf("%d\n",ans.size());
	for(i=0;i<ans.size();++i)printf("%d ",ans[i]);
}