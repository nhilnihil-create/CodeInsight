#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  vector<int> vec(3);
  cin>>vec[0]>>vec[1]>>vec[2];
  
  sort(vec.begin(),vec.end());
  
  if(vec[0]==vec[1]&&vec[1]==vec[2]){
    cout<<1<<endl;
  }
  else if(vec[0]==vec[1]&&vec[1]!=vec[2]){
    cout<<2<<endl;
  }
  else if(vec[0]!=vec[1]&&vec[1]==vec[2]){
    cout<<2<<endl;
  }
  else{
    cout<<3<<endl;
  }
}
