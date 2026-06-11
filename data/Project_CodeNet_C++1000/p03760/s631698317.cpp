#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    string o,e;
    cin>>o>>e;
    rep(i,o.size()){
        cout<<o[i];
        if(i<e.size()) cout<<e[i];
    }
    cout<<endl;
    return 0;
}