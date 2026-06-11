#include<bits/stdc++.h>
using namespace std;
int main(){
  string sa,sb,sc;
  cin>>sa>>sb>>sc;
  char c='a';
  for(int ia=0,ib=0,ic=0;;){
    if(c=='a'){
      if(ia==sa.size()){
        cout<<'A'<<endl;
        break;
      }
      c=sa.at(ia);
      ia++;
      continue;
    }
    if(c=='b'){
      if(ib==sb.size()){
        cout<<'B'<<endl;
        break;
      }
      c=sb.at(ib);
      ib++;
      continue;
    }
    if(c=='c'){
      if(ic==sc.size()){
        cout<<'C'<<endl;
        break;
      }
      c=sc.at(ic);
      ic++;
      continue;
    }
  }
}