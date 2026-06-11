#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007

int main(){
  int H,W;
  cin>>H>>W;
  vector<int> count(26,0);
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      char c;
      cin>>c;
      count.at(c-'a')++;
    }
  }
  bool flag=true;
  if(H%2==1&&W%2==1){
    int con=0;
    for(int i=0;i<26;i++){
      if(count.at(i)%2==1){
        con++;
        count.at(i)--;
      }
    }
    if(con>1){
      flag=false;
    }
    con=0;
    for(int i=0;i<26;i++){
      con+=count.at(i)/4;
    }
    if(con<(H/2)*(W/2)){
      flag=false;
    }
  }else{
    for(int i=0;i<26;i++){
      if(count.at(i)%2==1){
        flag=false;
      }
    }
    int con=0;
    for(int i=0;i<26;i++){
      con+=count.at(i)/4;
    }
    if(con<(H/2)*(W/2)){
      flag=false;
    }
  }
  if(flag){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
