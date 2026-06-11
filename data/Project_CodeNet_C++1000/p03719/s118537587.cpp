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

using namespace std;

ll mod(ll a, ll b) { return (a % b + b) % b; }
ll power(ll base, ll exp) 
{ll res=1;while(exp>0) {if(exp%2==1) res=(res*base);base=(base*base);exp/=2;}return res;}

int main()
{
	fast;
	ll A,B,C; cin>>A>>B>>C;
	if(C >= A && C <= B) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;	
} 