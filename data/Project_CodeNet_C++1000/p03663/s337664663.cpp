#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 110;

void query(const ll x){cout<<'?'<<' '<<x<<endl;fflush(stdout);}
char ttt[maxn];
bool get_res(){cin>>ttt;return ttt[0]=='Y'?true:false;}
void answer(const ll x){cout<<'!'<<' '<<x<<endl;fflush(stdout);}

ll pw[maxn],pw9[maxn];
bool e[maxn],e9[maxn];

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	ll l=1; for(int i=0;i<=10;i++,l*=10ll) pw[i]=l,query(l),e[i]=get_res();
	
	if(e[10])
	{
		l=9; for(int i=1;i<=9;i++,l=l*10ll+9ll) query(l),e9[i]=get_res(),pw9[i]=l;
		for(int i=9;i>=1;i--) if(!e9[i]) { answer(pw[i]);return 0; }
		answer(pw[0]); return 0;
	}
	int now=8;
	while(!e[now]) now--;
	if(now==0)
	{
		for(ll i=1;i<10;i++)
		{
			query(i*10);
			if(get_res()) { answer(i); return 0; }
		}
	}
	else
	{
		ll k=0;
		for(int i=0;i<now;i++)
		{
			ll l=1,r=9;
			while(l<=r)
			{
				ll mid=l+r>>1;
				query(k*10+mid);
				if(get_res()) l=mid+1;
				else r=mid-1;
			}l--;
			k=k*10+l;
		}
		k*=10ll;
		for(ll i=0;i<10;i++)
		{
			query((k+i)*10);
			if(get_res()) { answer(k+i); return 0; }
		}
	}
	
	return 0;
}
