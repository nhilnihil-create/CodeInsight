#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,y;
  cin>>x>>y;
  vector<int>vec={0,2,0,1,0,1,0,0,1,0,1,0};
 
  if(vec.at(x-1)==vec.at(y-1)){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  
}
