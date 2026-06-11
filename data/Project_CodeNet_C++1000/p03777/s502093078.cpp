#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vi>;


int main() {
  char a,b; cin >> a >> b;
  if(a=='H'&&b=='D'||a=='D'&&b=='H') cout << 'D' << endl;
  else cout << 'H' << endl;
}