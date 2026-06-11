#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n, m, a;
  vector<int> num(103);
  
  cin >> n >> m;
  
  rep(i, m * 2){
    cin >> a;
    num.at(a)++;
  }
  
  rep(i, n){
    cout << num.at(i + 1) << endl;
  }
  
  
  
}
