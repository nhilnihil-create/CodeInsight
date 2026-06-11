#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using P = pair<int,int>;
using ll = long long;

int main(){
  string n;
  cin >> n;
  int ans = 0;
  rep(i,n.size()){
    if(n[i] == '9') ans ++;
  }

  if(ans == 0){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }

  return 0;
}