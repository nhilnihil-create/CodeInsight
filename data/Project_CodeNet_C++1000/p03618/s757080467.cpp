#include <bits/stdc++.h>

#define int long long
//nitin try to think of dp(running state, point),segment tree generalised,binary search,trie (in last greedy)!!!!!!!!!!!!
#define ci(m)           for(int i=0;i<m;i++)
#define cj(m)           for(int j=0;j<m;j++)
#define ck(m)           for(int k=0;k<m;k++)
#define cis(m)          for(int i=1;i<=m;i++)
#define cjs(m)          for(int j=1;j<=m;j++)
#define cks(m)          for(int k=1;k<=m;k++)
#define rci(m)          for(int i=m-1;i>=0;i--)
#define rcj(m)          for(int j=m-1;j>=0;j--)
#define rck(m)          for(int k=m-1;k>=0;k--)
#define rcis(m)         for(int i=m;i>=1;i--)
#define rcjs(m)         for(int j=m;j>=1;j--)
#define rcks(m)         for(int k=m;k>=1;k--)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;
int e[200000][26];
int32_t main() {
    nitin;
    string str;
    cin>>str;
    int n=str.length();
    ci(n) e[i][str[i]-'a']++;
    rci(n) if(i!=n-1){
        cj(26)
        e[i][j]+=e[i+1][j];
    }
    int ans=0;
    ci(n) if(i!=n-1){
        cj(26) if(j!=str[i]-'a')
            ans+=e[i+1][j];
    }
    cout<<ans+1<<endl;
    return 0;
}