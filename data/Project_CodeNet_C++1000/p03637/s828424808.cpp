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
  vector<int> a(N);
  rep(i,N) cin >> a[i];
  int count1 = 0;
  int count4 = 0;
  rep(i,N)
  {
    if(a[i]%2==1)
    {
      count1 ++;
    }
    else if(a[i]%4==0)
    {
      count4 ++;
    }
  }
  if(count4>=count1)
  {
    cout << "Yes" << endl;
  }
  else if(count4+count1==N&&count4>=count1-1)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  
  return 0;
}
