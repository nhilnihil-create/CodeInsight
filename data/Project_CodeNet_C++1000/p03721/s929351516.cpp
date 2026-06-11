#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    ll n, k;
    cin >> n >> k;
    vector<pair<int,int>> v;
    ll sum = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    for(auto x: v){
        sum += x.second;
        if(sum >= k){
            ans = x.first;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}