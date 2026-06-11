#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int h,w; cin >> h >> w;
  vector<string> c(h);
  rep(i,h) cin >> c[i];
  vector<string> out(2*h);

  for(int i = 0;i<h;i++) cout << c[i] << endl << c[i] << endl;
  
  return 0;
}
