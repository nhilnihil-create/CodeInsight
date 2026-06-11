// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

typedef pair<int, int> P;

int main() {
  int n; cin >> n;
  vector<int> A(n), B;
  loop(i,0,n) cin >> A[i];
  int sum = 0;
  loop(i,0,n) {
    sum += A[i];
    if (A[i]%10 != 0) B.push_back(A[i]);
  }
  
  if (sum % 10 != 0) {
    cout << sum << endl;
    return 0;
  }
  
  if (B.size() == 0) {
    cout << 0 << endl;
    return 0;
  }
  
  sort(B.begin(), B.end());
  cout << sum - B[0] << endl;
  return 0;
}
