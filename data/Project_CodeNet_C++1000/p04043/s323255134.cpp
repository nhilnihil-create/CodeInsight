#include <bits/stdc++.h>
using namespace std;

int main() {
  vector <int>vec(3);
  cin>>vec.at(0)>>vec.at(1)>>vec.at(2);
  vector<int>veco={5,5,7};
  sort(vec.begin(),vec.end());
  if(veco==vec){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}
