#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=int64_t;

int group(int x) {
  int ret_val;
  switch (x) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      ret_val=0;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      ret_val=1;
      break;
    case 2:
      ret_val=2;
      break;
    default:
      break;
  }
  return ret_val;
}

int main() {
  int x,y; cin >>x >>y;
  cout <<(group(x)==group(y) ? "Yes":"No") <<endl;
  return 0;
}
