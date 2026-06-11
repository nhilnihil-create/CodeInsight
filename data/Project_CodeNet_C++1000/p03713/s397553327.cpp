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
	ll h,w;
	cin>>h>>w;
	ll ans = 1e18;
	for(int i = 1; i<=h; i++)
	{
		ll area1 = w*i, area2 = (h-i)/2 * w, area3 = h*w-area1-area2;
		ans = min(ans,max({area1,area2,area3})-min({area1,area2,area3}));
		area2 = w/2 *(h-i), area3 = h*w-area1-area2;
		ans = min(ans,max({area1,area2,area3})-min({area1,area2,area3}));
	}
	for(int i = 1; i<= w;i++)
	{
		ll area1 = h*i, area2 = (w-i)/2 * h, area3 = h*w-area1-area2;
		ans = min(ans,max({area1,area2,area3})-min({area1,area2,area3}));
		area2 = h/2 *(w-i), area3 = h*w-area1-area2;
		ans = min(ans,max({area1,area2,area3})-min({area1,area2,area3}));
	}
	cout<<ans<<endl;
	return 0;
}