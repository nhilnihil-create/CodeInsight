#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
  string o,e;
  cin >> o >> e;
  
  int diff = o.size() - e.size();
  
  int n = e.size();
  rep(i,n){
    cout << o[i] << e[i];
  }
  if(diff!=0) cout << o[n] << endl;
}