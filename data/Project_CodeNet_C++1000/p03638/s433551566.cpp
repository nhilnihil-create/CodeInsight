#include <bits/stdc++.h>
 using namespace std;
 using pii = pair<int, int>;
 using ll = long long;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;
 const int INFI = 1000000000;
 const ll INFL = (1LL << 60);

 int main() {
   int H, W, N;
   cin >> H >> W >> N;
   vector<int> a(N);
   rep(i, 0, N) cin >> a.at(i);

   vector<int> c_tmp(H * W);

   int cnt = 0;
   rep(i, 0, N) {
     rep(j, 0, a.at(i)) {
       c_tmp.at(cnt + j) = i + 1;
     }
     cnt += a.at(i);
   }

   vector<vector<int>> c(H, vector<int>(W));
   rep(i, 0, H) {
     rep(j, 0, W) {
       if (i % 2 == 0) c.at(i).at(j) = c_tmp.at(W * i + j);
       else c.at(i).at(W - 1 - j) = c_tmp.at(W * i + j);
     }
   }

   rep(i, 0, H) {
     rep(j, 0, W - 1) cout << c.at(i).at(j) << " ";
     cout << c.at(i).at(W - 1) << endl;
   }
 }
