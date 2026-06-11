#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)


int main(){
  int x,t;
  string s;
  cin >> x >> t;
  if ( t < x) cout << x-t << endl;
  else cout << 0 << endl;
  
  return 0;
}