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
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i,N) cin >> a[i];
  int ave;
  int sum = 0;
  rep(i,N) sum += a[i];
  ave = sum / N;
  int ansum = 0;
  int ansum2 = 0;
  rep(i,N)
  {
    ansum += (ave-a[i])*(ave-a[i]);
  }
  rep(i,N)
  {
    ansum2 += (ave+1-a[i])*(ave+1-a[i]);
  }
  cout << min(ansum,ansum2) << endl;
  return 0;
}
