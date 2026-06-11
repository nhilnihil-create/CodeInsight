#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int64_t> v(3);
  for(int i=0;i<3;i++){
    cin >> v.at(i);
  }
  sort(v.begin(),v.end());
  int64_t x=v.back()/2;
  int64_t y=v.back()-x;
  cout << v.at(0)*v.at(1)*(y-x) << endl;
  return 0;
}
