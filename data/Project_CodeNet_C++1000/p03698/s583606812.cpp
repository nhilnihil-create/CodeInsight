#include<bits/stdc++.h>
using namespace std;
/// Macros ---------------------
#define ll long long
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
/// Constracts -------------------
const int maxn=1e5;
const int INF=(1ll)<<(30ll);
const int inf=1000000000000000000;
const int eps=1e-9;
/// Quick Pow ---------------------
int qpow(int b,int e)
{
    if( !e ) return 1;
    if( e & 1 ) return qpow(b, e - 1) * b;
    int pwur = qpow(b, e >> 1);
    return pwur * pwur;
}

/// My Code ---------------------

int32_t main()
{
    set<char>st;
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        st.insert(s[i]);
    }
    if(st.size()==s.size())puts("yes");
    else puts("no");
}
