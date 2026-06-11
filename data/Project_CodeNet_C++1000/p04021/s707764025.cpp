#include<bits/stdc++.h>
#define FOR(i,a,b)for(int i=(a),_b=(b);i<=_b;i++)
#define FORN(i,b,a)for(int i=(b);_a=(a);i>=_a;i--)
#define REP(i,n)for(int i=0,_n=n;i<n;i++)
#define ll long long
#define pii pair<int,int>
#define re return
#define vi vector<int>
#define pb push_back
#define si set<int>
#define in insert
#define fl float
#define db double
#define ld long double
#define X first
#define Y second
#define st string
#define ull unsigned long long
#define size(s) s.size()
using namespace std;
inline void read(int &x)
{
	short negative=1;
    x=0;
    char c=getchar();
    while(c<'0' || c>'9')
    {
		if(c=='-')
			negative=-1;
		c=getchar();
	}
    while(c>='0' && c<='9')
        x=(x<<3)+(x<<1)+(c^48),c=getchar();
    x*=negative;
}
int main()
{
	int n;
	pii a[100100];
	cin>>n;
	REP(i,n)
	{
		int x;
		cin>>x;
		a[i]=make_pair(x,i);
	}
	sort(a,a+n);
	/*REP(i,n)
	{
		cout<<a[i].X<<" "<<a[i].Y<<endl;
	}*/
	int cnt=0;
	REP(i,n)
	{
		if((abs(a[i].Y-i))%2==1)cnt++;
	}
	cout<<cnt/2<<endl;
	return 0;
}
