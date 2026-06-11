#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  ll x;
  cin >> x;
  ll y = x / 11;
  ll z = x % 11;
  y *= 2;
  if (z < 7 && z != 0) y++;
  else if (z > 6) y += 2;
  cout << y << endl;
}
