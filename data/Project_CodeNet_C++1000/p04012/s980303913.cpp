#include<bits/stdc++.h>
using namespace std;
/// Macros ---------------------
#define ll long long
#define sz(a) (int)a.size()
#define int long long
#define pb push_back
#define vi vector<int>
#define f first
#define s second
#define ii pair<int,int>
#define lb lower_bound
#define up upper_bound
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define ld long double
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
/// Constracts -----------------------------------------------
const int maxn=1e5;
const int INF=(1ll)<<(30ll);
const int inf=1000000000000000000;
const int eps=1e-9;
const int mod=1e9+7;
/// Quick Pow ------------------------------------------------
int qpow(int b,int e)
{
    if( !e ) return 1;
    if( e & 1 ) return qpow(b, e - 1) * b;
    int pwur = qpow(b, e >> 1);
    return pwur * pwur;
}

int lcm(int a,int b){
    return a*b/__gcd(a,b);
}

/// My Code ---------------------------------------------------
map<char,int>mp;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    for(auto i:s)mp[i]++;
    bool fl=1;
    for(auto i:s){
        if(mp[i]%2)fl=0;
    }
    cout<<((fl)?"Yes\n":"No\n");

    return 0;
}
