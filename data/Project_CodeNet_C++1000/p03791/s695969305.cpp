#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

ll x[100001];
const int MOD = 1e9 + 7;
ll fact[100001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
		x[i]--;
	}
	fact[0]=1;
	for(int i=1;i<=100000;i++)
	{
		fact[i]=(fact[i-1]*i)%MOD;
	}
	ll ans = 1;
	int ptr = 1;
	ll target = 1;
	ll cnt = 1;
	for(int i = 0; i < n; i++)
	{
		while(ptr<n)
		{
			if(x[ptr]>target)
			{
				ptr++;
				target+=2;
				cnt++;
				continue;
			}
			else if(x[ptr]==target)
			{
				ptr++;
				cnt++;
				target+=2;
				break;
			}
			else break;
		}
		//cerr<<cnt<<'\n';
		ans=(ans*cnt)%MOD;
		target-=2;
		cnt--;
	}
	cout<<ans<<'\n';
	
}
