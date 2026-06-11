#include <bits/stdc++.h>
using namespace std;
 

int main() {
  string s;
  cin>>s;
  
  
  int N =s.size();
  int st=0;
  for(int i=0;i<N;i++){
    if(s.at(i)=='A'){
      st=i+1;
      break;
    }
  }
  int end =0;
  for(int i=0;i<N;i++){
    if(s.at(N-i-1)=='Z'){
      end=N-i;
      break;
    }
  }
  cout<<end-st+1<<endl;
}