#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int N=s.size();
  int a=0,A,b=0,B;
  for(int i=0;i<N;i++){
    if(s.at(i)=='A'){
      a=1;
      A=i;
      break;
    }
  }
  for(int i=N-1;i>-1;i--){
    if(s.at(i)=='Z'){
      b=1;
      B=i;
      break;
    }
  }
  cout<<B-A+1<<endl;
}