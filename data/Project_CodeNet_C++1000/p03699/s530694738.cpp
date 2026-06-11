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
  vector<int> s(N);
  rep(i,N) cin >> s[i];
  int sum = 0;
  sort(ALL(s));
  rep(i,N)
  {
    sum += s[i];
  }
  if(sum%10==0)
  {
    rep(i,N)
    {
      if(s[i]%10==0&&i==N-1)
      {
        cout << 0 << endl;
        return 0;
      }
      else if(s[i]%10!=0)
      {
        cout << sum - s[i] << endl;
        return 0;
      } 
    }
  }
  else
  {
    cout << sum << endl;
  }
  
  return 0;
}
