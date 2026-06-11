#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int64_t> v(3);
  for(int i=0;i<3;i++){
    cin >> v.at(i);
    if(v.at(i)%2==0){
      cout << 0 << endl;
      return 0;
    }
  }
  cout << min({v.at(0)*v.at(1),v.at(1)*v.at(2),v.at(0)*v.at(2)}) << endl;
  return 0;
}
