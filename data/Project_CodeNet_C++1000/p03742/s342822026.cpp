#include <bits/stdc++.h>
using namespace std;

typedef long long int LLI;

LLI A;
LLI B;

int main() {
  scanf("%lld%lld", &A, &B);
  if (llabs(A-B) <= 1) puts("Brown");
  else puts("Alice");
}
