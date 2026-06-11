#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int n, m;
    cin >> n >> m;
    vector<pair<ll,ll>> s(n), p(m);
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        s[i] = make_pair(a,b);
    } 
    for(int i = 0; i < m; i++){
        ll c, d;
        cin >> c >> d;
        p[i] = make_pair(c,d);
    } 

    for(int i = 0; i < n; i++){
        ll d = LINF;
        int point = 0;
        for(int j = 0; j < m; j++){
            if(d > abs(s[i].first - p[j].first) + abs(s[i].second - p[j].second)){
                d = abs(s[i].first - p[j].first) + abs(s[i].second - p[j].second);
                point = j + 1;
            }
        }
        cout << point << endl;
    }
    return 0;
}