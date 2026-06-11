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
#define forr(i, b, e)    for (ll i = b; i < e; i++)
 
 
using namespace std;
//using namespace __gnu_pbds;
typedef double lldb;
typedef pair<int, int>  ii;
typedef pair<double, double>  iidb;
typedef pair<ii, int>  iii;
typedef vector<ll>     vi;
typedef vector<vi>     vvi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll INF = 1e9+7;
const double PI = acos(-1);
#define initseg ll new_nodo=(pnodo*2),mid=(iz+der)/2;
 
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define tam 1010000
#define offset 200
#define ptr nodo*


using namespace std;
ll v[tam];
vector<int> g[tam];
int peso[tam];
int main()
{
	memset(peso,-1,sizeof peso);
    ios::sync_with_stdio(false);cin.tie(0);
   	int n;
   	cin>>n;
   	int iz,der;
   	forr(i,0,n-1)
   	{
   		cin>>iz>>der;
   		g[iz].pb(der);
   		g[der].pb(iz);
   	}
   	queue<int> cola;
   	peso[1]=1;
   	peso[n]=2;
   	cola.push(1);
   	cola.push(n);
   	while(!cola.empty())
   	{
   		int num=cola.front();
   		cola.pop();
   		for(int v:g[num])
   		{
   			if (peso[v]==-1)
   			{
   				peso[v]=peso[num];
   				cola.push(v);
   			}
   		}
   	}
   	int cblack=0;
   	forr(i,1,n+1)
   	{
   		//cout<<peso[i]<<' ';
   		if (peso[i]==peso[1])
   			cblack++;
   		else
   			cblack--;
   	}
   	//cout<<cblack<<endl;
   	if (cblack>0)
   		cout<<"Fennec\n";
   	else
   		cout<<"Snuke\n";
}