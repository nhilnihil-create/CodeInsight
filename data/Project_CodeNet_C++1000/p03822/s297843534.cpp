//还不是特别懂emm.....
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
const int MAXN=100000;
int a[MAXN+5],deg[MAXN+5],f[MAXN+5];
priority_queue<pair<int,int> > que;
int n;
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		scanf("%d",&a[i]),deg[a[i]]++;
	for(int i=1;i<=n;i++)
		if(!deg[i])
			que.push(make_pair(0,i));
	while(!que.empty())
	{
		int x=que.top().second;
		que.pop();
		f[a[x]]=max(f[a[x]],f[x])+1;
		deg[a[x]]--;
		if(!deg[a[x]])
			que.push(make_pair(-f[a[x]],a[x]));
	}
	printf("%d\n",f[1]);
	return 0;
}
/*
如果我们把打败关系看成一棵树的话，显然每次我们要选择一个叶节点和它的父亲比赛然后把它删掉。 
设f[x]表示以x为根的子树最少比赛多少场后只剩下x。 
假设我们删掉一个叶节点lea，其父亲为fa，那么有f[fa]=max(f[fa],f[lea])+1。 
为了使f[1]尽量小，显然我们应该每次找f最小的叶子删掉。 
用一个堆来维护叶子即可。
*/