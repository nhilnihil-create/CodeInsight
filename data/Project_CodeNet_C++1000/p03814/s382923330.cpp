#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int N=s.size();
  int a=0,b=0;
  for(int i=0;i<N;i++){
    if(s.at(i)=='A'){
      a=i+1;
      break;
    }
  }
  for(int i=0;i<N;i++){
    if(s.at(i)=='Z')
      b=i+1; 
  }
    
  cout << b-a+1 << endl;
}
