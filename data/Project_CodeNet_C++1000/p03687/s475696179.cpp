#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
  cin>>s;
  int N=s.size();
  s+='?';
  int ans=100;
  for(char i='a';i<='z';i++){
  int a=0;
    int b=0;
    for(int j=0;j<=N;j++)
      if(s.at(j)!=i && s.at(j)!='?')
        a++;
    else{
    if(b<a) b=a; a=0;
    }
  
     if(b<ans)
       ans=b;
  
  }cout<<ans<<endl;
   return 0;
}