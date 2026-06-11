#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  ll n, a, b;
  cin >> n >> a >> b;
  if(a>b) cout << 0 << endl;
  else if(a==b) cout << 1 << endl;
  else{
    if(n==1) cout << 0 << endl;
    else if(n==2) cout << 1 << endl;
    else{
      ll multi = n-2;
      cout << b*multi-a*multi+1 << endl;
    }
  }
  return 0;
}