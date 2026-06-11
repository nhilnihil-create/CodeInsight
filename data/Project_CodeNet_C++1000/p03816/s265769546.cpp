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
   if (card.size() % 2 == 1) cout << card.size() << endl;
   else cout << card.size() - 1 << endl;
 }
