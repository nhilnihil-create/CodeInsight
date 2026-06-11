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
set<pair<int, int>> F, cand;
ll ans[10];

void add_cand(int y, int x) {
   if (y >= 0 && y < H-2 && x >= 0 && x < W-2) cand.insert({y, x});
}

int main() {
   cin >> H >> W >> N;
   rep (i, N) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      F.insert({a, b});
      for (int dy = 0; dy < 3; dy++) {
         for (int dx = 0; dx < 3; dx++) {
            add_cand(a-dy, b-dx);
         }
      }
   }

   ans[0] = (ll)(H-2) * (W-2);
   for (auto c : cand) {
      int y = c.first, x = c.second;
      int num = 0;
      for (int i = 0; i < 3; i++) {
         for (int j = 0; j < 3; j++) {
            if (F.count({y+i, x+j})) ++num;
         }
      }
      ans[0]--;
      ans[num]++;
   }

   for (int i = 0; i <= 9; i++) {
      printf("%lld\n", ans[i]);
   }

   return 0;
}