#include<bits/stdc++.h>
using namespace std;
#define vi               vector<int>
#define pii              pair<int,int>
#define si               set<int>
#define mii              map<int,int>
#define umii              unordered_map<int,int>
#define p_b              push_back
#define loop(i,a,b)      for(int i=a;i<b;i++)
#define setbits(x)       __builtint_popcountll(x) //return no. of set bits in x
#define zerobits(x)      __buitlin_ctzll(x)       // return no. of zeroes after first set bit
#define int              long long
#define io          	 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define multipletest     int t;cin>>t;while(t--) 
bool isPrime(int n){if(n==1){return false;}if(n==2){return true;}if(n%2==0){return false;}for(int i = 3; i <= sqrt(n); i+=2){if(n % i == 0){return false;}}return true;}
string make_beautiful(string x , int k){for(int i = k; i<x.size();i++){ x[i]=x[i-k];}return x;
}
 


long long binpow(long long a, long long b) {long long res = 1; while (b > 0) { if (b & 1) res = res * a;a = a * a;b >>= 1;}return res;}
 
// for GCD -> __gcd(a,b);
 
int LCM(int x , int y) { return (x * y)/__gcd(x,y); }
 
const int mod = 100000;
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////f//////////////////////////////////////////////////////////////////////////////


void solve()
{
	string s;
	cin>>s;
	bool south=false , north = false , east = false , west = false;

	for(int i=0;i<s.size() ; i++)
	{
		if(s[i] == 'S') south = true;
		if(s[i] == 'W') west = true;
		if(s[i] == 'N') north = true;
		if(s[i] == 'E') east = true;
	}

	if( (south && !north) || (east && !west) || (!south && north) || (!east && west))
		cout<<"No\n";
    else cout<<"Yes\n";

}

 
int32_t main()
{
	
	io
 	// multipletest
	solve();
}