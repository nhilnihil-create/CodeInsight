#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORD(i,b,a) for (int i = (int)(b) - 1; i >= a; --i)
#define REP(i,N) FOR(i,0,N)
#define st first
#define nd second
#define pb push_back

typedef pair<int, int> PII;
typedef long long LL;

int N;
int A[222222];

const char* FIRST = "First\n";
const char* SECOND = "Second\n";

int gcd(int a, int b) {
  return b ? gcd(b, a%b) : a;
}

bool go() {
  LL sum = 0;
  REP(i,N) sum += A[i];
  if (sum % 2 == 0) {
    return true;
  }

  bool found = false;
  REP(i,N) if (A[i] % 2 && A[i] > 1) {
    --A[i];
    found = true;
    break;
  }
  if (!found) return false;

  int g = A[0];
  REP(j,N) g = gcd(g, A[j]);
  REP(j,N) A[j] /= g;

  return !go();
}

int main() {
  scanf("%d", &N);
  LL sum = 0;
  REP(i,N) {
    scanf("%d", &A[i]);
    sum += A[i];
  }
  if (N == 1) {
    printf(A[0] == 1 ? SECOND : FIRST);
    return 0;
  }
  if (N % 2 == 0) {
    printf(sum % 2 ? FIRST : SECOND);
    return 0;
  }

  bool res = go();
  printf(res ? FIRST : SECOND);
  return 0;
}
