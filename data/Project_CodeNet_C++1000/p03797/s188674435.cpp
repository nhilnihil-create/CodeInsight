#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
#define rall(a) (a).rbegin(),(a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    ll n, m; cin >> n >> m;
    if(n*2 <= m){
        cout << n + (m-n*2)/4 << endl;
    }
    else{
        cout << min(n,m/2) << endl;
    }
}