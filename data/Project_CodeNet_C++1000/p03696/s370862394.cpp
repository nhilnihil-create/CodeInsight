#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,d=0,mi=0,i;
  string s;
  cin>>n>>s;
  for(i=0;i<n;i++){
    if(s.at(i)=='(') d++;
    else if(s.at(i)==')'){
      d--;
      mi=min(mi,d);
    }
  }
  if(mi<0){
    for(i=0;i<-mi;i++) s='('+s;
    d-=mi;
  }
  if(d>0) for(i=0;i<d;i++) s+=')';
  cout<<s<<endl;
}