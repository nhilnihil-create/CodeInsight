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

const int A = 100001;
int main() {
  int n;
  cin >> n;
  vector<int> v(A);
  int m = 0;
  rep(i,n){
    int a;
    cin >> a;
    v[a]++;
    if(v[a]>1) ++m;
  }
  int ans = n-(m+1)/2*2;
  cout << ans << endl;
}