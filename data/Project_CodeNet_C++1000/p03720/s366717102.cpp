#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> vec(n);
  rep(i,2*m){
    int x;
    cin >> x;
    vec[x-1]++;
  }
  rep(i,n) cout << vec[i] << endl;

}