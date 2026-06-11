#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int N=100005;
int n,A[N],in[N];
vector <int> e[N];
vector <LL> v[N];
LL solve(int x,int pre){
	vector <LL> &a=v[x];
	for (auto y : e[x])
		if (y!=pre)
			a.push_back(solve(y,x));
	if (a.empty())
		return A[x];
	sort(a.begin(),a.end());
	if (!~*a.begin())
		return -1;
	reverse(a.begin(),a.end());
	LL tot=0;
	for (auto y : a)
		tot+=y;
	LL mx=min((LL)A[x],min(tot/2,tot-*a.begin()));
	LL Need=tot-A[x];
	return Need>mx||Need<0?-1:(A[x]-Need);
}
int main(){
	n=read();
	for (int i=1;i<=n;i++)
		A[i]=read();
	for (int i=1;i<=n;i++)
		e[i].clear();
	for (int i=1;i<n;i++){
		int a=read(),b=read();
		e[a].push_back(b);
		e[b].push_back(a);
		in[a]++,in[b]++;
	}
	if (n==2)
		return puts(A[1]==A[2]?"YES":"NO"),0;
	int rt=0;
	for (int i=1;!rt&&i<=n;i++)
		if (in[i]>1)
			rt=i;
	puts(solve(rt,0)==0?"YES":"NO");
	return 0;
}