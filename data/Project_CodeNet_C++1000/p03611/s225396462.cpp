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
  int N;
  cin >> N;
  vector<int> vec(N);
  vector<int> zana(100005);
  rep(i,N)
  {
    cin >> vec[i];
    zana[vec[i]] ++;
  }
  sort(ALL(vec));
  int M = 0;
  rep(i,100000)
  {
    int X = zana[i] + zana[i+1] + zana[i+2];
    M = max(M,X);
  }
  cout << M << endl;
  return 0;
}
