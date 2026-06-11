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

int main() {
   int N;
   cin >> N;
   vec<int> p(N);
   vec<int> d(N);
   rep (i, N) {
      cin >> p[i];
      p[i]--;
   }

   int cnt = 0;
   repp (i, 0, N-1) {
      if (p[i] == i) {
         swap(p[i], p[i+1]);
         cnt++;
      }
   }
   if (p[N-1] == N-1) {
      cnt++;
   }
   cout << cnt << endl;

   return 0;
}