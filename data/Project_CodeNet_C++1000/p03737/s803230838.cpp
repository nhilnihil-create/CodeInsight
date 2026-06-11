#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF (long long)(1e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)

int main(void)
{
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  ll d = 'A'- 'a';
  printf("%c%c%c\n", (char)(s1[0]+d), (char)(s2[0]+d), (char)(s3[0] + d));
}
