#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin >> n;
	n++;
	deque<int> ans;
	int cur=1;
	for (int i=62-__builtin_clzll(n);i>=0;i--)
	{
		ans.insert(ans.begin()+ans.size()/2,cur);
		ans.push_front(cur);
		cur++;
		if (n&(1LL<<i))
		{
			ans.push_front(cur);
			ans.push_back(cur);
			cur++;
		}
	}
	printf("%d\n",ans.size());
	for (int i:ans)
	printf("%d ",i);
}