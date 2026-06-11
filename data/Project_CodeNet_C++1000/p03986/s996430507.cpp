#include<bits/stdc++.h>
using namespace std;
int main(){
string x;
  cin>>x;
  int N=x.size();
  map<char,int>M;
  M['S']=0;
  M['T']=0;
  for(int i=0;i<N;i++){
  if(x.at(i)=='S')
    M.at('S')++;
    else{
    if(0<M.at('S')){
    M.at('S')--;
    }else{
    M.at('T')++;
    }
    
    }
  
  }int ans=M.at('S')*2;
  cout<<ans<<endl;
   return 0;
}