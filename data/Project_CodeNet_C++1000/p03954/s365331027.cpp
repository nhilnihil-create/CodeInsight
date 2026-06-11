#include <bits/stdc++.h>
using namespace std;
/*---define tricks---*/
#define ALL(v) v.begin(),v.end()
#define UN(v) sort(ALL(v)),v.erase(unique(ALL(v)),v.end())
#define FILL(x,y) memset(x,y,sizeof(x))
#define EACH(v,it) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define revsort(b,e) sort(b,e),reverse(b,e)
/*---define types---*/
typedef long long ll;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
/*---define variables---*/
int n,m;
int L,R,M,ans;
int base[200000];
bool B[200000];
/*---define function---*/

bool check(int x)
{
	for(int i=1;i<m;++i)
	{
		B[i]=(base[i]>=x?1:0);
	}
	for(int i=n-1;i>0;i--)
	{
		if((B[i]!=B[n])&&(B[m-i]!=B[n])) 
		{
			B[n]=!B[n];
		}
		else
		{
			return B[n];
		}
	}
	return B[n];
}

/*---main code---*/
int main()
{
	FIO;
	cin>>n;
	m=2*n;
	for(int i=1;i<m;++i)
	{
		cin>>base[i];
	}
	L=1,R=m-1;
	while(L<=R)
	{
		M=(L+R)>>1;
//		cout<<L<<' '<<R<<' '<<M<<'\n';
		if(check(M))
		{
			L=M+1;
			ans=M;
		}
		else
		{
			R=M-1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
