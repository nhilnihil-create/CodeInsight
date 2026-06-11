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

int main() {
  int n;
  cin >> n;
  int v1=0,v4=0;
  rep(i,n){
    int a;
    cin >> a;
    if(a%4==0) ++v4;
    else if(a%2==1) ++v1;
  }
  bool ans = v1<=v4 || (v1==v4+1&&v1+v4==n);
  cout << (ans?"Yes":"No") << endl;
}
