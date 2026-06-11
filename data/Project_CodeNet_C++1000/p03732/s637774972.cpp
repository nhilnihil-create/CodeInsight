#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,w;
	cin>>n>>w;
	ll w2 = w;
	ar<ll,2> a[n];
	for(int i = 0;i <n; i++)
		cin>>a[i][0]>>a[i][1];
	sort(a,a+n);
	vector<int > v[4];
	v[0].push_back(0);
	v[1].push_back(0);
	v[2].push_back(0);
	v[3].push_back(0);
	ll y = a[0][0],j=0;
	ar<ll,4> s={0,0,0,0};
	s[j]= y;
	vector<ll > g2;
	for(auto it:a)
	{
		if(y==it[0])
		{
			g2.push_back(it[1]);
			// v[j].push_back(v[j][v[j].size()-1]+it[1]);
		}
		else
		{
			sort(g2.begin(),g2.end(),greater<ll>());
			for(auto i = g2.begin(); i!=g2.end(); i++)
				v[j].push_back(v[j][v[j].size()-1]+(*i));
			// cout<<v[j].size()<<endl;
			g2.clear();
			j++;
			// v[j].push_back(v[j][v[j].size()-1]+it[1]);
			g2.push_back(it[1]);
			y = it[0];
			s[j]=y;
		}
	}
	sort(g2.begin(),g2.end(),greater<ll>());
	for(auto it:g2)
	{
		v[j].push_back(v[j][v[j].size()-1]+(it));
	}
	ll g = w/a[0][0],ans =0;
	for(ll i = 0 ;i<=min((ll)v[0].size()-1,g); i++)
	{
		ll y = v[0][i];
		ll w2 = i*(s[0]);
		if(w2<=w)
			ans = max(ans,y);
		if(s[1]>0)
		for(ll j2 = 0; j2<=min(w/(a[0][0]+1),(ll)v[1].size()-1); j2++)
		{
			ll y2 = v[1][j2];
			ll w3 = j2*(s[1]);
			if(w2+w3<=w)
				ans = max(ans,y+y2);
			if(s[2]>0)
			for(ll k = 0; k<=min(w/(a[0][0]+2),(ll)v[2].size()-1); k++)
			{
				ll y3 = v[2][k];
				ll w4 = k*(s[2]);
				if(w2+w3+w4<=w)
					ans = max(ans,y+y2+y3);
				// cout<<ans<<" "<<k<<" "<<j2<<" "<<i<<" "<<w2<<endl;
				if(s[3]>0)
				for(ll l = 0; l<=min(w/(a[0][0]+3),(ll)v[3].size()-1); l++)
				{
					ll y4 = v[3][l];
					ll w5 = l*(s[3]);
					if(w2+w3+w4+w5<=w)
						ans = max(ans,y+y2+y3+y4);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}