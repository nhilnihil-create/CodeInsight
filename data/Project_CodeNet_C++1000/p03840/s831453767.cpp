#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  ll ai, ao, at, aj, al, as, az;
  cin >> ai >> ao >> at >> aj >> al >> as >> az;
  ll result = 0;
  result += ao;
  ll ijl1 = ai/2*2 + aj/2*2 + al/2*2;
  ll ijl2 = (ai-1)/2*2 + (aj-1)/2*2 + (al-1)/2*2 + 3;
  result += (ai==0||aj==0||al==0) ? ijl1 : max(ijl1, ijl2);
  cout << result << endl;
  return 0;
}