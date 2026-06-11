#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;

void solve(){
  char a, b; cin >> a >> b;
  if(a == 'H'){
    cout << b << endl;
  }
  else{
    if(b == 'H') cout << 'D' << endl;
    else cout << 'H' << endl;
  }
  return;
}

int main(){
  solve();
  return 0;
}
