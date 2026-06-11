#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()	
{
	int x,tc,ans = 0;
	cin>>tc;
	map<int,bool> m;
	while(tc--){
		cin>>x;
		m[x] = (m[x] + 1)%2;
		if(m[x]) ans++;
		else ans--;
	}
	cout<<ans<<'\n';
}