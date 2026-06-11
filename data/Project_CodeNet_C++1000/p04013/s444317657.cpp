#include<bits/stdc++.h>
using namespace std;

long long solve(int N,int A,vector<vector<vector<long long>>> dp){
  long long sum=0;
  for(int j=1;j<=N;j++){
    sum+=dp.at(N).at(j).at(j*A);
  }
  return sum;
}

int main(){
  int N,A;
  cin >> N >> A;
  vector<int> x(N);
  for(int i=0;i<N;i++){
    cin >> x.at(i);
  }
  vector<vector<vector<long long>>> dp(N+1,vector<vector<long long>> (N+1,vector<long long>(2501)));
  for(int i=0;i<=N;i++){
    for(int j=0;j<=i;j++){
      for(int k=0;k<=2500;k++){
        if(i==0&&j==0&&k==0){
          dp.at(i).at(j).at(k)=1;
        }
        else if(1<=i && k<x.at(i-1)){
          dp.at(i).at(j).at(k)=dp.at(i-1).at(j).at(k);
        }
        else if(1<=i&&1<=j&&x.at(i-1)<=k){
          dp.at(i).at(j).at(k)=dp.at(i-1).at(j).at(k)+dp.at(i-1).at(j-1).at(k-x.at(i-1));
        }
        else{
          dp.at(i).at(j).at(k)=0;
        }
      }
    }
  }
  cout << solve(N,A,dp) << endl;
}