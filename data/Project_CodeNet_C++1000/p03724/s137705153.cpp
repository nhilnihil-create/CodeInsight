#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,m;
  cin >> n >> m;
  vector<int>data(n);
  rep(i,0,m){
    int a,b;
    cin >> a >> b;
    --a;--b;
    data[a]++;
    data[b]++;
  }
  rep(i,0,n){
    if(data[i]%2 != 0){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}