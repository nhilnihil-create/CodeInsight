#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<int>>sec(2,vector<int>(2));
  cin >>sec.at(0).at(0)>>sec.at(0).at(1)>>sec.at(1).at(0)>>sec.at(1).at(1);
  int tmp1=0,tmp2=0;
  int ans=0;
  for(int i=0;i<=100;i++){
    if(i>=sec.at(0).at(0)&&i>=sec.at(1).at(0)&&i<=sec.at(0).at(1)&&i<=sec.at(1).at(1)){
      tmp1=i;
      break;
    }
    if(i==100){
      cout <<0<<endl;
    return 0;
    }
  }
  for(int i=tmp1;i<=100;i++){
    if((i>=sec.at(0).at(1)&&i<=sec.at(1).at(1))||(i<=sec.at(0).at(1)&&i>=sec.at(1).at(1))){
      tmp2=i;
      break;
    }
  }
  cout <<tmp2-tmp1<<endl;
}