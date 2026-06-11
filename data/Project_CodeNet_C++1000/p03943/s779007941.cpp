#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> v(3);
  int sum=0;
  for(int i=0;i<3;i++){
    cin >> v.at(i);
    sum+=v.at(i);
  }
  sort(v.begin(),v.end());
  if(sum-v.back()==v.back()){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
