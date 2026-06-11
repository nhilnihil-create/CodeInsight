#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define ull unsigned ll 
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,n) for (int i=1;i<=(n);i++)
#define RREP(i,n) for (int i=(n)-1; i>=0; i--)
#define pii pair<int,int>
#define f first
#define s second
#define SZ(x) x.size()
#define ALL(x) x.begin(), x.end()
#define ull unsigned ll 
#define pb push_back
#define SQ(x) (x)*(x)
#define endl '\n'
using namespace std;
ll mod=1e9+7;
int main() 
{ 
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll x,y; cin>>x>>y;
	if (abs(x-y)<=1) cout<<"Brown"<<endl;
	else cout<<"Alice"<<endl; 
} 