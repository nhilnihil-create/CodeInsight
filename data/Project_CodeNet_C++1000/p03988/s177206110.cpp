#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

// #define int ll

const int maxn = 1e5+5;
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"Impossible\n"; exit(0);}


main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    srand(time(NULL));
    int n; cin>>n;
    vector<int> v (n), a(n);
    REP(i,n) {
    	cin>>a[i]; v[a[i]]++;
    }
    sort(ALL(a));
    int mx = a[a.size()-1], mn = a[0];
    if (mn!=(mx+1)/2) GG();
    if (v[mn]!=(mx%2+1)) GG();
    FOR(i,mn+1, mx){
    	if (v[i]<2) GG();
    }
    cout<<"Possible"<<endl;

}