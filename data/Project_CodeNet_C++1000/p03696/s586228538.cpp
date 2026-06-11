#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

int main() {
  int N;
  cin>>N; 
  string s;
  cin>>s;
  
  int ri=0;//"("
  int le=0;//")"
  rep(j,s.size()){
    if(s.at(j)=='('){
      ri++;
    }
    if(s.at(j)==')'&&ri>0){
      ri--;
    }
    else if(s.at(j)==')'&&ri==0){
      le++;
    }
  }
  
  while(ri--){
    s=s+')';
  }
  while(le--){
    s='('+s;
  }
  
  cout<<s<<endl; 
}