#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
#define mp make_pair
using ll=long long;
using ld=long double;
typedef pair<int,ll> P;
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
    int n;ll k;
    cin >> n >> k;

    vector<P> ab(n);
    
    rep(i,n){
        cin >> ab[i].first >> ab[i].second;
    }
    ssort(ab);
    rep(i,n-1)ab[i+1].second+=ab[i].second;
    int i=0;
    while(ab[i].second<k){
        ++i;
    }
    cout << ab[i].first << endl;
}