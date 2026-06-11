#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=(s);i<(n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define REPR(i,s,n) for(int i=(s);i>=(n);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define Eunique(v) v.erase(unique(all(v)),v.end())
#define pvec(v) rep(i,v.size()){cout << v[i] << " ";};cout<<endl;
#define pb push_back
#define pf push_front
#define mod 1e9+7
 
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;

const double pi = acos(-1.0);
 
ll gcd(ll x, ll y) { return (y == 0) ? x : gcd(y, x % y); }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

int main()
{
	char c[12];
	rep(i,12) cin >> c[i];
	rep(i,12){
		if(i==4) cout << " ";
		cout << c[i];
	}
	cout << endl;
	return 0;
}