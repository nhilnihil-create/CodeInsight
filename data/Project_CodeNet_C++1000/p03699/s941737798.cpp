#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main(){
  int N; cin >>N;
  vector<int> check(N);
  int sum=0;
  rep(i,0,N) {
    cin >>check[i];
    sum+=check[i];
  }
  if (sum%10) {
    cout <<sum <<endl;
    return 0;
  } else {
    sort(check.begin(),check.end());
    rep(i,0,N) {
      if (check[i]%10) {
        cout <<sum-check[i] <<endl;
        return 0;
      }
    }
  }
  cout <<0 <<endl;
  return 0;
}
