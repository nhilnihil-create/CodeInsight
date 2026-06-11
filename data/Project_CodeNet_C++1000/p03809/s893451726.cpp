#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
int n,A[N],in[N];
vector <LL> e[N],v[N];
LL solve(int x,int pre){
	vector <LL> &a=v[x];
	for (auto y : e[x])
		if (y!=pre)
			a.push_back(solve(y,x));
	if (a.empty())
		return A[x];
	sort(a.begin(),a.end());
	if (!~a[0])
		return -1;
	reverse(a.begin(),a.end());
	LL tot=0;
	for (auto y : a)
		tot+=y;
	LL u=min((LL)A[x],min(tot/2,tot-a[0])),v=tot-A[x];
	return v>u||v<0?-1:(A[x]-v);
}
int main(){
	cin >> n;
	for (int i=1;i<=n;i++)
		cin >> A[i];
	for (int i=1,a,b;i<n;i++){
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
		in[a]++,in[b]++;
	}
	if (n==2)
		return puts(A[1]==A[2]?"YES":"NO"),0;
	for (int i=1;i<=n;i++)
		if (in[i]>1)
			return puts(solve(i,0)==0?"YES":"NO"),0;
}