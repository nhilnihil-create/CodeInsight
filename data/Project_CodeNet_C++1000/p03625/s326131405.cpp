#include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;

 int main() {
     int N;
     cin >> N;

     map<ll, ll> cnt;
     vector<ll> mt2;

     rep(i, 0, N) {
       ll A;
       cin >> A;
       cnt[A]++;
     }

     for (pair<ll, ll> p : cnt) {
       if (p.second >= 2) mt2.push_back(p.first);
     }


     ll a, b;

     if (mt2.empty()) cout << 0 << endl;
     else {
       a = mt2.back();
       if (cnt[mt2.back()] >= 4) b = a;
       else b = mt2.at(mt2.size() - 2);
       cout << a * b << endl;
     }
 }
