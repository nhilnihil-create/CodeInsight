#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define sz(x) (int)(x).size();
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
int32_t main()
{
	int n=in();
	string s;
	cin>>s;
	int ob=0,cb=0;
	for(auto i:s)
	{
		if(i==')')
		{
			if(ob)ob--;
			else cb++;
		}
		if(i=='(')ob++;
	}
	string a(cb,'(');cout<<a;
	cout<<s;string b(ob,')');
	cout<<b;
	
}