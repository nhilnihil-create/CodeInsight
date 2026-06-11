#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  int n;
  int count =0;
  cin >> n;
  vector<int> l(n),r(n);
  rep(i,n){
    cin >> l[i] >> r[i];
    count +=(r[i]-l[i]+1);
  }
  cout << count <<endl;

  return 0;
}
