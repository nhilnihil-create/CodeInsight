#include"bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#define empb emplace_back
#define mp make_pair
#define F first
#define S second
#define endl "\n"
#define vii vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define mapii map<int,int> 
#define mapll map<ll,ll>
#define all(a) a.begin(),a.end()
#define test ll t; cin>>t; while(t--)
#define prec(n) fixed<<setprecision(n)
#define jaldibazi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007




int main() {

	int n, l; cin >> n >> l;
	vector<string> vs;

	for(int i = 0; i<n; ++i) {
		string a; cin >> a;
		vs.push_back(a);
	}

	// for(int i )

	sort(vs.begin(),vs.end());
	string res = "";

	for(int i = 0; i<n; ++i) {
		res+=vs[i];
	}

	cout << res << "\n";
	return 0;

} 
