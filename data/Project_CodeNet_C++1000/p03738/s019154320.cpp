#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define sz(X) ((int)(X).size())
#define endl "\n";
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	string a,b;
	cin>>a>>b;
    if (a==b)
	{
		cout<<"EQUAL";
		return 0;
	}
	if (sz(a)==sz(b))
	{
	  if(a[0]<b[0]) cout<<"LESS"; else cout<<"GREATER";
	  return 0;
	}
	
	if(sz(a)<sz(b)) cout<<"LESS"; else cout<<"GREATER";
	

   return 0;
}
