#include <bits/stdc++.h>
 
#define gcd(m,n) __gcd(m,n)
#define lcm(m,n) m*(n/gcd(m,n))
#define fast std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pi acos(-1.0)
#define endl '\n'
#define MOD 1000000007
#define ull unsigned long long
#define ll long long
#define ld long double
#define pb push_back
#define dbg(x) cout << #x << "  " << x << endl;
 
/* DSU 
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}
*/ 
ll power(ll base, ll exp) 
{ll res=1;while(exp>0) {if(exp%2==1) res=(res*base);base=(base*base);exp/=2;}return res;}
 
ll mod(ll a, ll b) {return (a % b + b) % b;}
 
ll powerm(ll base,ll exp,ll mod) 
{ll ans=1;while(exp){if(exp&1) ans=(ans*base)%mod;exp>>=1,base=(base*base)%mod;}return ans;}
 
using namespace std;

int main()
{
	fast;
	ll n; cin>>n; ll arr[n]; for(ll i = 0; i < n; i++) cin>>arr[i];
	unordered_map<ll,ll>mp; ll others = 0;
	for(ll i = 0; i < n; i++)
	{
		if(arr[i] >= 1 && arr[i] <= 399)
			mp[0]++;
		else if(arr[i] >= 400 && arr[i] <= 799)
			mp[1]++;
		else if(arr[i] >= 800 && arr[i] <= 1199)
			mp[2]++;
		else if(arr[i] >= 1200 && arr[i] <= 1599)
			mp[3]++;
		else if(arr[i] >= 1600 && arr[i] <= 1999)
			mp[4]++;
		else if(arr[i] >= 2000 && arr[i] <= 2399)
			mp[5]++;
		else if(arr[i] >= 2400 && arr[i] <= 2799)
			mp[6]++;
		else if(arr[i] >= 2800 && arr[i] <= 3199)
			mp[7]++;
		else if(arr[i] >= 3200)
		{
			others++;
		}
	}
	if(mp.size() == 0)
	{
		cout << 1 << " " << others << endl;
	}
	else if(others == 0)
	{
		cout << mp.size() << " " << mp.size() << endl;
	}
	else
		cout << mp.size() << " " << others + mp.size() << endl;
	return 0;
}