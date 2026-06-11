#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string n; cin >> n;
  string r; for(int i = n.size()-1;i>=0;--i) r.push_back(n[i]);

  if(n==r) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
