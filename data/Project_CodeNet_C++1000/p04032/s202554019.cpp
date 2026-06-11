#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;

  int N=s.size();
  int x=-1,y=-1;
  //2
  for(int i=0;i<N-1;++i){
    if(s[i]==s[i+1]){
      x=i+1,y=i+2;
    }
  }
  //3
  for(int i=0;i<N-2;++i){
    if(s[i]==s[i+2]){
      x=i+1,y=i+3;
    }
  }

  cout<<x<<" "<<y<<endl;
}