// ArC061
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vvi vector<vector<int>>
#define vec vector
#define pq priority_queue
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for (int (i) = (0); (i) < (n); ++(i))
#define repp(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) cerr<<"("<<#x<<", "<<#y<<") = "<<"("<<x<<", "<<y<<")"<<endl;
#define debug3(x, y, z) cerr<<"("<<#x<<", "<<#y<<", "<<#z<<") = "<<"("<<x<<", "<<y<<", "<<z<<")"<<endl;
#define debugB(x, y) cerr<<#x<<": "<<bitset<y>(x) << endl;
#define line() cerr << "---------------" << endl;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};

template<typename T>
void printA(vector<T> &printArray, char between = ' ') {
   int paSize = printArray.size();
   for (int i = 0; i < paSize; i++) { cerr << printArray[i] << between;}
   if (between != '\n') {cerr << endl;}
}

// ------------------------------------------------------------------------------------------

int H, W, N;
set<pair<int, int>> B, cand;

void add(int y, int x) {
   if (y >= 0 && y < H-2 && x >= 0 && x < W-2) {
      cand.insert({y, x});
   }
}

int main() {
   cin >> H >> W >> N;
   rep (i, N) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      B.insert({a, b});
      rep (y, 3) {
         rep (x, 3) {
            add(a-y, b-x);
         }
      }
   }

   vec<ll> ans(10);
   ans[0] = 1LL * (H-2) * (W-2);
   for (auto c : cand) {
      int y = c.first, x = c.second;
      int cnt = 0;
      rep (i, 3) {
         rep (j, 3) {
            if (B.find({y+i, x+j}) != B.end()) {
               cnt++;
            }
         }
      }
      ans[cnt]++;
      ans[0]--;
   }

   for (ll x : ans) {
      cout << x << endl;
   }

   return 0;
}