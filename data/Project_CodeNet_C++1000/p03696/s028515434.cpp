#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  string s;
  cin>>s;
  map<char,int>M;
  M[')']=0;
  M['(']=0;
  for(int i=0;i<N;i++){
  if(s.at(i)=='(')
    M.at('(')++;
    else{
    if(M.at('(')==0)
      M.at(')')++;
      else
        M.at('(')--;
    
    }
  
  }int R=M.at(')');
  int L=M.at('(');
  for(int i=0;i<R;i++)
    s='('+s;
  for(int i=0;i<L;i++)
    s+=')';
  cout<<s<<endl;
  
   return 0;
}