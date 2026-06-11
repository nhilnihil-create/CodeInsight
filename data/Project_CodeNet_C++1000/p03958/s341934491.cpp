#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
#define mp make_pair
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<ll>>;
#define MAX 1000000007

int main()
{
    int k,t;
    cin >> k >> t;
    vector<int> a(t);
    vector<int> tmp(t);
    rep(i,t)cin >> a[i];
    rep(i,t){
        tmp[i]=k-a[i];
    }
    int ans=0;
    rep(i,t){
        if(a[i]-1>tmp[i])ans+=(a[i]-1-tmp[i]);
    }
    cout << ans << endl;
}