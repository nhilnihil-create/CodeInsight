#include <bits/stdc++.h>
#define pii pair<int, int>
#define int long long
using namespace std;

int N, A, B;
int AA[55];
long double fact[55];
long long C[50][50];
void pre() {
  fact[0] = 1;
  for(int i = 1; i <= 50; i++) {
    fact[i] = fact[i - 1] * i;
  }
}

long double combin(int A, int B) {
  return fact[B] / fact[A] / fact[B - A];
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin >> N >> A >> B;
  pre();
  for(int i = 1; i <= N; i++) {
    cin >> AA[i];
  }
  sort(AA + 1, AA + N + 1, greater<int>());
  long double sum = 0;
  int last = -1, cntlast = 0;
  for(int i = 1; i <= A; i++) {
    sum += AA[i];
    if(AA[i] != last) {
      last = AA[i];
      cntlast = 1;
    }else cntlast++;
  }
  int cntlastA = cntlast;
  for(int i = A + 1; i <= N; i++) {
    if(AA[i] == last) {
      cntlast++;
    }
  }
  cout << fixed;
  cout << setprecision(6) << sum / A << "\n";
  if(cntlastA == A) {
    long double ans = 0;
    for(int i = A; i <= min(cntlast, B); i++) {
      ans += combin(i, cntlast);
    }
    cout << setprecision(0) << ans << '\n';
  }else {
    cout << setprecision(0) << combin(cntlastA, cntlast) << "\n";
  }
}