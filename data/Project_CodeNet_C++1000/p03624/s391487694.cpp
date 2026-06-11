#include <bits/stdc++.h>
using namespace std;
      
int main(){
  string S;cin>>S;
  vector<int> vec(26,0);
  int size=S.size();
  for(int i=0;i<size;i++){
    vec.at((int)S.at(i)-97)++;
  }
  int std;
  for(int j=0;j<26;j++){
    if(vec.at(j)==0){
      std=j;
      break;
    }
    else{
      std=-1;
    }
  }
  if(std>=0){
    int k=std+97;
    cout<<(char)k<<endl;
  }
  else{
    cout<<"None"<<endl;
  }
  
}
