#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
void solve()
{
	ll x1,y1,x2,y2,i;
	string s1="",s2="",f1="",f2="",f="";
	cin>>x1>>y1>>x2>>y2;
	for(i=0;i<(y2-y1);i++)
	{
		s1=s1+"U";
		s2=s2+"D";
	}
	for(i=0;i<(x2-x1);i++)
	{
		s1=s1+"R";
		s2=s2+"L";
	}
	
	f1=s1+s2;
	s1="LU"+s1+"RD";
	s2="RD"+s2+"LU";
	f2=s1+s2;
	f=f1+f2;
	cout<<f<<endl;
}

	int main()
	{
//#ifndef ONLINE_JUDGE
//		freopen("input.txt", "r", stdin);
//		freopen("output1.txt", "w", stdout);
//#endif
		ll t = 1;
		//cin >> t;
		while (t--)
		{
			solve();
		}
	}