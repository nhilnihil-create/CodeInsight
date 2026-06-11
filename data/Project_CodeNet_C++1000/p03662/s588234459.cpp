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

int N;
vec<vec<int>> G;

void dfs(int pos, vec<int> &dist) {
   if (dist[pos] == -1) return;
   for (int to : G[pos]) {
      if (dist[to] == -1) {
         dist[to] = dist[pos] + 1;
         dfs(to, dist);
      }
   }
}

int main() {
   cin >> N;
   G = vec<vec<int>>(N);
   rep (i, N-1) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      G[a].push_back(b);
      G[b].push_back(a);
   }
   vec<int> dist1(N, -1), dist2(N, -1);
   dist1[0] = 0;
   dfs(0, dist1);
   dist2[N-1] = 0;
   dfs(N-1, dist2);

   int b = 0, w = 0;
   rep (i, N) {
      if (dist1[i] <= dist2[i]) {
         b++;
      } else {
         w++;
      }
   }

   if (b > w) {
      puts("Fennec");
   } else {
      puts("Snuke");
   }

   return 0;
}