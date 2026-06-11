#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  string s;
  cin>>s;
  vector<int> a;
  for(int i=0;i<s.size();i++){
    if(s[i]=='0'){
      a.push_back(0);
    }
    else if(s[i]=='1'){
      a.push_back(1);
    }
    else{
      if(a.size()!=0){
      a.pop_back();
      }
    }
  }
    for(int i=0;i<a.size();i++){
      cout<<a.at(i);
    }
  
    cout<<"\n";
  
  return 0;
}