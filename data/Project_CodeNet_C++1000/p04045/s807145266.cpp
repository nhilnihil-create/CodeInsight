#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

bool d[10];
bool f(int n){
  while(n>0){
    if(d[n%10]) return false;
    n /= 10;
  }
  return true;
}
int main() {
  int n,k;
  cin >> n >> k;
  rep(_,k){
    int i;
    cin >> i;
    d[i] = true;
  }
  while(!f(n)) ++n;
  cout << n << endl;
}
