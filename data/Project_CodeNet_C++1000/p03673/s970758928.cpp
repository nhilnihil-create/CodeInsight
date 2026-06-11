#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int n; cin >>n;
  deque<int> ans;
  rep_eq(i,1,n) {
    int a; cin >>a;
    int temp1=i%2;
    int temp2=n%2;
    if (temp1==temp2) {
      ans.push_front(a);
    } else {
      ans.push_back(a);
    }
  }
  rep(i,0,ans.size()) {cout <<ans[i] <<' ';}
  return 0;
}
