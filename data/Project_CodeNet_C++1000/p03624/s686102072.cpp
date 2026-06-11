#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin>>S;
  int s=S.size();
  map<char,int> ma;
  for(int i=0;i<s;i++){
    ma[S[i]]++;
  }
  for(char c='a';c<='z';c++){
    if(ma[c]==0){
      cout<<c<<endl;
      return 0;
    }
  }
  cout <<"None"<<endl;
}
//電車のなかでACしました褒めてください