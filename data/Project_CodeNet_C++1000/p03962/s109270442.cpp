#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n = 3;
  vector<int> a(n); rep(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  a.erase(unique(a.begin(),a.end()),a.end());
  cout << a.size() << endl;
    
  return 0;
}
