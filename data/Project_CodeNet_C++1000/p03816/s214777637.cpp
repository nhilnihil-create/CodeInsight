#include <bits/stdc++.h>
 using namespace std;
 using pii = pair<int, int>;
 using ll = long long;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;
 const int INFI = 1000000000;
 const ll INFL = (1LL << 60);

 int main() {
   ll N;
   cin >> N;
   vector<int> A(N);
   map<int, int> card;
   rep(i, 0, N) {
     cin >> A.at(i);
     card[A.at(i)]++;
   }
   int ans = 0, cnt = 0;
   for (auto p : card) {
     if (p.second == 1) continue;
     else if (p.second % 2 == 1) ans += p.second / 2;
     else {
       ans += (p.second - 2) / 2;
       cnt++;
     }
   }
   ans += (cnt + 1) / 2;
   cout << N - ans * 2 << endl;
 }
