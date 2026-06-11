#include <bits/stdc++.h>
using namespace std;





int main() {
  vector<int> vec{0,2,0,1,0,1,0,0,1,0,1,0};
  int A,B;
  
  
  cin>>A>>B;
  
  if (vec.at(A-1)==vec.at(B-1)){
    cout<<"Yes"<<endl;
  }
  else {
    cout<<"No"<<endl;
  }
  
}











