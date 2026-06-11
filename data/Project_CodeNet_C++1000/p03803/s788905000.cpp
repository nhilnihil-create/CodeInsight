#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;

void solve(){
  int a, b; cin >> a >> b;
  if(a == 1){
    if(b == 1) cout << "Draw\n";
    else cout << "Alice\n";
  }
  else if(b == 1){
    cout << "Bob\n";
  }
  else if(a > b){
    cout << "Alice\n";
  }
  else if(a < b){
    cout << "Bob\n";
  }
  else cout << "Draw\n";
  return;
}

int main(){
  solve();
  return 0;
}
