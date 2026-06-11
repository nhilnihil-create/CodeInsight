#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

const ll P = 1000000007;
const long long INF = 1LL << 60;
int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main()
{
  cout << fixed << setprecision(10);
  string S;
  cin >> S;
  int N = S.size();
  int n = 0;
  int s = 0;
  int e = 0;
  int w = 0;
  rep(i,N)
  {
    if(S[i]=='N') n++;
    if(S[i]=='S') s++;
    if(S[i]=='E') e++;
    if(S[i]=='W') w++;
  }
  if(n>0&&e>0&&w>0&&s>0)
  {
    cout << "Yes" << endl;
  }
  else if(n==0&&s==0&&e>0&&w>0)
  {
    cout << "Yes" << endl;
  }
  else if(e==0&&w==0&&n>0&&s>0)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}
