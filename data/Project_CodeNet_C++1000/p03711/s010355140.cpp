#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin >> a >> b;
  bool c=true;
  vector<int> vec{0,1,3,1,2,1,2,1,1,2,1,2,1};
  
  if(vec.at(a)!=vec.at(b)){
    c=false;
  }
  
  if(c){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }  
}