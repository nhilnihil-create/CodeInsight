#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_poizcy.hpp>
typedef long long  ll;
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define mem(a,h)          memset(a, (h), sizeof(a))
#define fi first
#define se second
#define por(a,b) (((a%MOD) * (b%MOD))%MOD)
#define forg(i, b, e, c)    for (ll i = (ll)b; i < (ll)e; i+=c)
#define forr(i, b, e)    for (int i = b; i < e; i++)
 
 
using namespace std;
//using namespace __gnu_pbds;
typedef long double lldb;
typedef pair<ll, ll>  ii;
typedef pair<lldb, lldb>  iidb;
typedef pair<ll, ii>  iii;
typedef vector<ll>     vi;
typedef vector<ll>      vll;
//typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll INF = 1e9+7;
const lldb PI = acos(-1);
#define initseg ll new_nodo=(nodo*2),mid=(iz+der)/2;
 
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define tam 2020000
#define offset 200
#define ptr nodo*
const ll MOD=1e9+7;
#define lazy first
#define sum second
ll N=50;
vector<ll> v(50,0);
void doit()
{
	ii minn={1e18,0};
	forr(i,0,N)
	{
		minn=min(minn,{v[i],i});
	}
	forr(i,0,N)
	{
		if (minn.se==i)
			v[i]+=N;
		else
			v[i]--;
	}
}
int main()
{
	forr(i,0,N)
		v[i]=i;
	ll K;
	cin>>K;
	forr(i,0,N)
	v[i]+=(K/N);
	K%=N;
	while(K!=0)
	{
		doit();
		K--;
	}
	cout<<N<<endl;
	forr(i,0,N)
		cout<<v[i]<<' ';
}