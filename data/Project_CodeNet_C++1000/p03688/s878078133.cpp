#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n;
  cin >> n;
  set<int> s;
  vector<int> c(n,0);
  rep(i,n){
    int a;
    cin >> a;
    s.insert(a);
    c[a]++;
  }
  if(s.size() > 2) cout << "No" << endl;
  else if (s.size() == 1) {
    int p = *s.begin();
    if(n == p+1 || n >= 2*p) cout << "Yes" << endl;
    else cout << "No" << endl;
  } else {
    int p = *s.begin(); s.erase(p);
    int q = *(s.begin());
    if(q - p != 1) cout << "No" << endl;
    else {
      if(c[p] < q && c[q] >= (q-c[p])*2) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
  return 0;
}