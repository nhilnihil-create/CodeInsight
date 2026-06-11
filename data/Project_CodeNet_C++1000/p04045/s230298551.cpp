#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 
  int64_t n,k;
  cin>>n>>k;

  vector<char> d(k);
  for(int64_t i=0;i<k;i++){
    cin>>d.at(i);
  }

  bool flg=true;
  int64_t number=0;
  for(int64_t i=n;i<=n*10;i++){
    string str=to_string(i);
    flg=true;
    for(int j=0;j<str.size();j++){
      for(int l=0;l<k;l++){
        if(str.at(j)==d.at(l)){
          flg=false;
        }
      }
    }
    if(flg){
      number=i;
      break;
    }
  }
  
  cout<<number<<endl;


  return 0;
}