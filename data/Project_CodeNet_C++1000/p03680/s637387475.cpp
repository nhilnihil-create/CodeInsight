#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,p=0,c=0;
  cin >> n;
  vector<int> vec(n);
  vector<bool> check(n,false);
  for(int i=0;i<n;i++){
    cin >> vec.at(i);
  }
  while(p!=1){
    if(check.at(p)){
      break;
    }else{
      check.at(p) = true;
      p = vec.at(p)-1;
      c++;
    }
  }
  if(p==1)
    cout << c << endl;
  else
    cout << -1 << endl;
}