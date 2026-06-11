#include<bits/stdc++.h>

#define ll long long int 
#define FOR(i,N) for(i=0;i<(N);i++)
#define FORe(i,N) for(i=1;i<=(N);i++)
#define FORr(i,a,b) for(i=(a);i<(b);i++)
#define ii pair<ll,ll>
#define vi vector<ll>
#define vii vector<ii>
#define ff first 
#define ss second 
#define mp make_pair
#define pb push_back
#define ldd long double 
#define cd complex<double>
#define vcd vector<cd>
#define all(x) (x).begin(),(x),end()

using namespace std;

const ll MAXN = 1e5+5;
const ll MOD = 1e9+7;
const ll INF = 1e17+1011;
const ll ROOTN = 320;
const ll LOGN = 17;

const ldd PI = acos(-1);
const ldd EPS = 1e-7;

const short int __PRECISION = 9;
const short int Alp = 26;

int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll i,freq[Alp],ans = 1;
	string s;
	cin>>s;
	FOR(i,Alp)
		freq[i] = 0;
	FOR(i,s.size())
		freq[(s[i] - 'a')]++;
	ans = (s.size()*(s.size()-1))/2 + 1;
	FOR(i,Alp)
		ans -= (freq[i]*(freq[i]-1))/2;
	cout<<ans;
	return 0;
}