#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    ll a,b, x; cin >> a >> b >> x;
    if(a == 0) cout << b / x + 1 << endl;
    else cout << b / x -(a - 1) /x << endl;
}