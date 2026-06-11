#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string n;
  cin >> n;

  if(n[0]==n[2]){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  return 0;
}