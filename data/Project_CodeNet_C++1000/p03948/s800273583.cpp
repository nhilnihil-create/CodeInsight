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
int n,l;
int a[100005];
priority_queue<int> s;
/*---define function---*/

/*---main code---*/
int main()
{
	FIO;
	cin>>n>>l;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	s.push(a[n]);
	int mval=INT_MIN,msum=0;
	for(int i=n-1;i>0;--i)
	{
		int nval=s.top()-a[i];
		if(nval>mval)
		{
			mval=nval,msum=1;
		}
		else if(nval==mval)
		{
			msum++;
		}
		s.push(a[i]);
	}
	cout<<msum<<'\n';
	return 0;
}
