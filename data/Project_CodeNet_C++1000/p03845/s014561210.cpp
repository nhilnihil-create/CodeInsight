#include<iostream>
#include<vector>
using namespace std;

int main(){
  //情報取得
  int N;
  cin>>N;
  vector<int>problem(N);
  for(int i=0;i<N;i++){
   cin>>problem.at(i); 
  }
  int M;
  cin>>M;
  vector<vector<int>>drink(2,vector<int>(M));
  for(int i=0;i<M;i++){
   cin>>drink.at(0).at(i)>>drink.at(1).at(i); 
  }
  //計算結果出力
  for(int i=0;i<M;i++){
    int ans=0;
    for(int j=0;j<N;j++){
       if(drink.at(0).at(i)-1==j){
        ans+=drink.at(1).at(i);
       }else{
        ans+=problem.at(j);
       }
     }
    cout<<ans<<endl;
  }
  return 0;
}