#include <bits/stdc++.h>
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b)for(int i=(int)(a);(i)<(int)(b);i++)

typedef unsigned long long ull;
typedef long long ll;

const int INF = 1001001001;
const ll MOD = 1e9 + 7;

using namespace std;
using P = pair<int,int>;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }

int main() {
  int n; cin >> n;

  int a[n];
  rep(i, n) {
      cin >> a[i];
  }
  
  bool colors[8] = {false};
  int count = 0; int count_min = 0; int count_max = 0;
  rep(i, n) {
      if (1<=a[i] && a[i]<=399) colors[0] = true;
      else if (400<=a[i] && a[i]<=799) colors[1] = true;
      else if (800<=a[i] && a[i]<=1199) colors[2] = true;
      else if (1200<=a[i] && a[i]<=1599) colors[3] = true;
      else if (1600<=a[i] && a[i]<=1999) colors[4] = true;
      else if (2000<=a[i] && a[i]<=2399) colors[5] = true;
      else if (2400<=a[i] && a[i]<=2799) colors[6] = true;
      else if (2800<=a[i] && a[i]<=3199) colors[7] = true;
      else { count_max++; }
  }

  rep(i, 8) {
      if (colors[i]) count++;
  }
  if (count == 0) count_min = 1;
  cout << count+count_min << " " << count+count_max << endl;
  
  return 0;
}