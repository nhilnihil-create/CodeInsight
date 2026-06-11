#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
#define FAST  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define ar array 
 
 
int main() {
	FAST;
 
	//int t;
	//cin >> t;
	//while(t--) 
	{
		int a,b,c;
		cin>>a>>b>>c;
		map<int,int> m;
		m[a]++,m[b]++,m[c]++;
		if(m[5]==2&&m[7]==1)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
}
