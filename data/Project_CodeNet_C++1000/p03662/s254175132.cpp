#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cctype>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstring>
#include<list>
//#include<windows.h>
//#include<time.h>
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define mer make_pair
#define mme memset
#define ao(a) (a.begin(),a.end())
using namespace std;

const double pie1=3.1415926;//π1
const double pie2=3.14159265358979;//π2
const double pie3=3.14159265358979323846;//π3
const int vbi=999999999;
const int vli=-vbi;
const long long vbl=999999999999999999;
const long long vll=-vbl;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
typedef pair<pii,pii> pi4;
typedef pair<pll,ll> plll;
typedef pair<int,pii> ipii;
typedef pair<ll,pll> lpll;
typedef pair<pll,pll> pl4;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef set<int> sti;
typedef set<ll> stl;
typedef set<pii> spi;
typedef set<pll> spl;
priority_queue<int> pqi;
priority_queue<ll> pql;
queue<int> qi;
queue<ll> ql;

/*void bin_v(){
	char bin[1000];
	gets(bin);
}*/

bool pss(int a){
	for(int i=2;i<=sqrt(a);i++)
		if(a%i==0)
			return false;
	return true;
}
/////////////////////////////////////////////////////////////////////////////////////////

int n,m;
vector<int> v[100010];
vector<int> lj;
int col[100010];

bool dfs(int now,int last){
	lj.pb(now);
	if(now==n)
		return true;
	for(int i=0;i<v[now].size();i++)
		if(v[now][i]!=last)
			if(dfs(v[now][i],now))
				return true;
	lj.ppb();
	return false;
}

void dfs2(int now,int last,int c){
	if(col[now]==(3-c))
		return;
	col[now]=c;
	for(int i=0;i<v[now].size();i++)
		if(v[now][i]!=last)
			dfs2(v[now][i],now,c);
}

int main(){
	//my name is Veex_WCY
	ios::sync_with_stdio(false);
	cin>>n;
	m=n-1;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1,-1);
	for(int i=0;i<ceil(lj.size()*1.0/2);i++){
		col[lj[i]]=1;
	}
	for(int i=ceil(lj.size()*1.0/2);i<lj.size();i++)
		col[lj[i]]=2;
	dfs2(1,-1,1);
	dfs2(n,-1,2);
	int sum1,sum2;
	for(int i=1;i<=n;i++){
		if(col[i]==1)
			sum1++;
		else
			sum2++;
//		cout<<col[i]<<' ';
	}
	if(sum1>sum2)
		cout<<"Fennec";
	else
		cout<<"Snuke";
	return 0;
}
