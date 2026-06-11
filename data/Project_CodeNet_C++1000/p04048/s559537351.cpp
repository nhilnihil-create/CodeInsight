#include<bits/stdc++.h>
using namespace std;
long long solve(long long a, long long b)
{
  if(a%b == 0) return (2*(a/b)-1)*b;
  return 2*(a/b)*b + solve(b, a%b);
}
int main()
{
  long long N, X;
  scanf("%lld%lld", &N, &X);
  printf("%lld\n", solve(N-X, X)+N);
}