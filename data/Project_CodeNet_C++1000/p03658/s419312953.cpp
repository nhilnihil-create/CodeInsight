#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
   ll n, k;
   cin >> n >> k;
   vector<ll> v(n);
   for(ll i = 0; i < n; ++i){
        cin >> v[i];
   }
   sort(v.begin(), v.end(), greater<ll>());
   cout << accumulate(v.begin(), v.begin() + k, 0);
}
