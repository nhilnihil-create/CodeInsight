#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

const ll P = 1000000007;
int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main()
{
  cout << fixed << setprecision(10);
  string A,B,C;
  cin >> A >> B >> C;
  int a = A.size();
  int b = B.size();
  if(A[a-1]==B[0]&&B[b-1]==C[0])
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
  return 0;
}
