#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define gc getchar
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define x1 uvuvwe
#define y1 onyetvwe
#define x2 onyette
#define y2 ugmewuben
typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
template <typename T> void scan(T &angka){
	angka=0;char input=gc();T kali=1;
	while(!(48<=input&&input<=57)){	if(input=='-')	kali=-1;input=gc();}
	while(48<=input&&input<=57)	angka=(angka<<3)+(angka<<1)+input-48,input=gc();angka*=kali;
}
template <typename T1,typename T2> void scan(T1 &angka1,T2 &angka2){
	scan(angka1);scan(angka2);
}
int nodes,root=1;
vector <int> node[100005];
int dfs(int now,int par=-1){
	int ret=0;
	for(auto v:node[now])
	{
		if(v==par)
			continue;
		ret^=dfs(v,now)+1;
	}
	return ret;
}
int main()
{
	scan(nodes);
	for(int i=1;i<=nodes-1;i++)
	{
		int u,v;
		scan(u,v);
		node[u].pb(v);
		node[v].pb(u);
	}
	if(dfs(root)==0)
		cout<<"Bob"<<endl;
	else
		cout<<"Alice"<<endl;
}