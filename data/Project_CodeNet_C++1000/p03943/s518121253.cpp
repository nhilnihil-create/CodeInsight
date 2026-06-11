#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  vector<int> x(3);
  for(int i=0; i<3; i++){
    cin >> x.at(i);
  }
  sort(x.begin(), x.end());
  if(x.at(0)+x.at(1)==x.at(2)){
    cout << "Yes";
  }else{
    cout << "No";
  }
  return 0;
}