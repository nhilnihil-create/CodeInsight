#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first
#define se second
#define pi 3.1415926535
#define mod1 1000000007
#define mod2 1000000009
#define mp make_pair
#define no_of_digits(n) floor(log10(n)) + 1
#define lcm(a, b) (a/__gcd(a,b)*b)

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  int k = 2*n;
  int a[2*n];
  for(int i = 0; i < k; i++){
    cin >> a[i];
  }

  sort(a, a+k);
  ll sm = 0;
  for(int i = 0; i < k; i += 2){
    sm += a[i];
  }

  cout << sm;
  return 0;
}

