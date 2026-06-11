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
  int N,H,W;
  cin >> H >> W >> N;
  vector<int> a(N);
  rep(i,N) cin >> a[i];
  vector<int> k;
  rep(i,N)
  {
    rep(j,a[i])
    {
      k.pb(i+1);
    }
  }
  vector<vector<int>> grid(H,vector<int>(W));
  rep(i,H)
  {
    rep(j,W)
    {
      if(i%2==0)
      {
        grid[i][j] = k[i*W+j];
      }
      else
      {
        grid[i][W-1-j] = k[i*W+j]; 
      }
      
    }
  }
  rep(i,H)
  {
    rep(j,W)
    {
      if(j!=W-1) cout << grid[i][j] << " ";
      else cout << grid[i][j] << endl;
    }
  }
  return 0;
}
