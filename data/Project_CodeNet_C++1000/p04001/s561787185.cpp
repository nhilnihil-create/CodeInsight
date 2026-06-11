#include <bits/stdc++.h>
using namespace std;

int main() {
  //入力
  string S;
  cin>>S;
  int len=S.length();
  long long temp=0;
  long long totalans=0;
  //bit全探索
  for(int i=0;i<(1 <<(len-1));i++){
    temp=0;
    for(int j=0;j<len;j++){
      temp=temp*10;
      temp+=S.at(j)-'0';
      if(i&(1<<j)){
        //cout<<"###"<<temp<<endl;
        totalans+=temp;
        temp=0;
      }
    }
    //cout<<"#"<<temp<<endl;
    totalans+=temp;
  }
  
  cout<<totalans<<endl;
  return 0;       
}