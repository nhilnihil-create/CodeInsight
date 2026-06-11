//#pragma GCC optimize(\"Ofast,no-stack-protector\")
//#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx\")
//#pragma GCC target(\"avx,tune=native\")
// Neil

#include<bits/stdc++.h>

using namespace std;

typedef complex<double> base;
typedef long double ld;
typedef long long ll;

#define endl "\n"
#define pb push_back
#define pii pair<int,int>
#define pll pair< ll , ll >
#define vi vector<int>
#define vvi vector< vi >
const int MAXN=(int)(2e5+5);
const ll MOD=(ll)(1e9+7);
int t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, k, x,y;
    cin>>n>>k>>x>>y;
    cout<<x*min(n,k) + y*max(n-k,0)<<endl;
    return 0;
}