#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <map>
#include <list>
using namespace std;

// int main() {
//   long long N,K;
//   cin >> N >> K;
//   long long a[N],b[N];
//   for(int i = 0; i < N; ++i) cin >> a[i] >> b[i];
//   long long bsum = 0;
//   for(int i = 0; i < N; ++i){
//     bsum += b[i];
//   }
//   long long air[bsum];
//   for(int i = 0; i < N; i += b[i]){
//     for(int j=0; j<b[i]; ++j){
//       air[i+j]=a[i];
//     }
//   }
//   sort(air,air + bsum-1);
//   cout << air[K-1] << endl;
// }


using ll = long long;
const int AMAX = 100000;
ll cnt[AMAX + 1];

int main(void) {
  int N;
  ll K;
  cin >> N >> K;

  for (int i = 0; i < N; ++i) {
    int A, B;
    cin >> A >> B;
    cnt[A] += B;
  }

  for (int ans = 1; ans <= AMAX; ++ans){
    if (K <= cnt[ans]) {
      cout << ans << endl;
      break;
    }
    K -= cnt[ans];
  }
  return 0;
}