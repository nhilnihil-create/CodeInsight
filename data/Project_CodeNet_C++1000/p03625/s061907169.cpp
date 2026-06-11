#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static bool larger(const int& a, const int& b) {return a > b;}
int main()
{
  int N;
  cin >> N;
  vector <int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end(), larger);
  int l = 0, s = 0, pl = 0, ps = 0;
  for (int i = 0; i < N; i++) {
    if (l == 0) {
      if (A[i]==pl) {
        l = pl;
      } else {
        pl = A[i];
      }
    } else if (s == 0) {
      if (A[i]==ps) {
        s = ps;
      } else {
        ps = A[i];
      }
    }
  }
  cout << (long long)l*s << endl;
  return 0;
}
