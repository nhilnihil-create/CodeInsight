#include <bits/stdc++.h>
using namespace std;



int main() {
  string S;
  cin>>S;
  
  vector<char> vec(20,'2');
  
  int m=0;
  for(int i=0;i<S.size();i++){
    if(S.at(i)=='1'){
      m++;
      vec.at(m)='1';
    }
    else if(S.at(i)=='0'){
      m++;
      vec.at(m)='0';
    }
    else{
      vec.at(m)='2';
      m--;
      m=max(0,m);
    }
  }
  for(int i=1;i<20;i++){
    if(vec.at(i)=='1'||vec.at(i)=='0'){
      cout<<vec.at(i);
    }
    else break;
  }
  cout<<endl;
      
}