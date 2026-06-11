#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define PB push_back
#define ll long long
using namespace std;
template <class T>
inline void rd(T &x)
{
	x=0; char c=getchar(); int f=1;
	while(!isdigit(c)){if(c=='-')f=-1; c=getchar();}
	while(isdigit(c)) x=x*10-'0'+c,c=getchar(); x*=f;
}
const int N=1e5+10;
vector<int> s[N],tmp;
int n,dep[N];
void sol(int u) {
	if(!s[u].size()) return;
	for(int i=0;i<s[u].size();++i) sol(s[u][i]);
	for(int i=0;i<s[u].size();++i) tmp.PB(dep[s[u][i]]);
	sort(tmp.begin(),tmp.end(),greater<int> ());
	int ans=s[u].size();
	for(int i=0;i<tmp.size();++i) ans=max(ans,tmp[i]+i+1);
	tmp.clear();
	dep[u]=ans;
//	cerr<<u<<' '<<dep[u]<<endl;
}
int main() {
	rd(n);
	for(int i=2,x;i<=n;++i) rd(x),s[x].PB(i);
	sol(1);
	printf("%d\n",dep[1]);
	return 0;
}