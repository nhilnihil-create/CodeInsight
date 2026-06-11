#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
   int N, M;
   cin >> N >> M;
   vector<int> a(N), b(N), c(M), d(M);

   for(int i=0; i<N; i++) {
      cin >> a[i] >> b[i];
   }
   for(int j=0; j<M; j++) {
      cin >> c[j] >> d[j];
   }


   for(int i=0; i<N; i++) {
      int min_d = abs(a[i]-c[0])+ abs(b[i]-d[0]);
      int ans = 1;
      for(int j=0; j<M; j++) {
         if(min_d > abs(a[i]-c[j])+ abs(b[i]-d[j])) {
            min_d = abs(a[i]-c[j])+ abs(b[i]-d[j]);
            ans = j + 1;
         }
      }
      cout << ans << endl;
   }
}