#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
   ll n, k, m, s = 0;
   cin >> n >> k;
   vector<pair<ll, ll>>v;
   for (ll i = 0; i < n; i++)  {
        ll x, y;
        cin >> x >> y;
        v.push_back({x, y});

   }
   sort(v.begin(), v.end());
   for (ll i = 0; i < v.size(); i++) {
    k = k - v[i].second;
    if(k <= 0){
        m = i;
        break;
    }
   }
   cout << v[m].first << endl;
   return 0;
}
