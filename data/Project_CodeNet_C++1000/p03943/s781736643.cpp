#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  vector<int> x(3);
  rep(i,0,3) cin >>x[i];

  sort(x.begin(),x.end());

  cout <<(x[0]+x[1]==x[2] ? "Yes":"No") <<endl;
}
