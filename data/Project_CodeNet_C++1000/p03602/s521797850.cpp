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
typedef pair<ll, ll>  ii;
typedef pair<double, ii>  iii;
typedef pair<double, double>  iidb;
typedef vector<ll>     vi;
typedef vector<vi>     vvi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll INF = 1e9+7;
const double PI = acos(-1);
#define initseg ll new_nodo=(pnodo*2),mid=(iz+der)/2;
 
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define tam 3300
#define offset 3000
#define ptr nodo*
const ll MOD=1e9+7;

using namespace std;
int arrpa[tam];
int peso[tam][tam];
int findpa(int num){if (arrpa[num]==num)return num;return arrpa[num]=findpa(arrpa[num]);}
int main()
{	
	forr(i,0,tam)arrpa[i]=i;
	int n;ll tot=0;
	cin>>n;
	forr(i,0,n)
	{
		forr(j,0,n){
			cin>>peso[i][j];	
			tot+=peso[i][j];
		}
	}
	bool invalid=0;

	set<ii> s;
	forr(k,0,n)
	{
		forr(i,0,n)
		{
			forr(j,0,n)
			{
				if (i==k|| j==k)continue;
				int ant=peso[i][j];
				peso[i][j]=min(peso[i][j],peso[i][k]+peso[k][j]);
				if (ant!=peso[i][j])
					invalid=1;
				else if (ant==peso[i][k]+peso[k][j])
					s.insert({min(i,j),max(i,j)});
			}
		}
	}
	for(auto par:s)
		tot-=2*peso[par.fi][par.se];
	
	if (invalid)
		cout<<"-1\n";
	else
	{
		cout<<tot/2<<endl;
	}
}		