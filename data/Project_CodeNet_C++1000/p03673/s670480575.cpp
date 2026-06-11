#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n;
  cin >> n;
  vector<ll> l(0), r(0);

  rep(i,n) {
    int a;
    cin >> a;
    r.push_back(a);
    swap(l,r);
  }

  int nl = l.size();
  int nr = r.size();
  for(int i = nl-1; i >=0; i--){
    cout << l[i] << " ";
  }
  for(int i = 0; i < nr; i++){
    cout << r[i] << " ";
  }
  cout << endl;
  
}
