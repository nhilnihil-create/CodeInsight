#include <bits/stdc++.h> 
using namespace std; 
//#define endl "\n";
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
const long long int mod=pow(10,9)+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n,m,x,y;
	cin>>n>>m;
	vector<int>b(n,1);
	vector<bool>v(n,false);
	v[0]=true;
	for(int i=0;i<m;i++)
	{
	    ll x,y;
	    cin>>x>>y;
	    x--;y--;
	    b[x]--;
	    b[y]++;
	    if(v[x]==true)
	        v[y]=true;
	    if(b[x]==0)
	        v[x]=false;
	}
	ll ans=0;
	for(int i=0;i<v.size();i++)
	    if(v[i])
	        ans++;
	cout<<ans<<endl;
    return 0;
}
