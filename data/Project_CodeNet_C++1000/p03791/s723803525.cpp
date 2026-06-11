#include <bits/stdc++.h>

#define INF (1e9)
#define INF_LL (1e17)

using LL = long long;
using ULL = unsigned long long;

using namespace std;

#define mod 1000000007

#define MAX_N 100005

int N;
LL A[MAX_N];

void input()
{
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
}

LL solve()
{
  LL ret = 1;
  stack<int> Stack;
  for (int i = 0; i < N; i++) {
    Stack.push(A[i]);
    LL k = Stack.size();
    if(A[i] < 2*k-1){
      Stack.pop();
      ret *= k;
      ret %= mod;
    }
  }
  for (LL i = 1; i <= Stack.size(); i++) {
    ret *= i;
    ret %= mod;
  }

  return ret;
}

int main()
{
  input();

  cout << solve() << endl;

  return 0;
}
