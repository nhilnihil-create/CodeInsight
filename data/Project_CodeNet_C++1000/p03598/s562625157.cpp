#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int n,k;
  cin >> n >> k;
  int len=0;
  vector<int> x(n);
  rep(i,n){
    cin >> x[i];
  }
  rep(i,n){
    if(abs(x[i])<abs(k-x[i])){
      len +=2*abs(x[i]);
    }else len += 2*abs(k-x[i]);
  }
  cout << len << endl;
  return 0;
}
