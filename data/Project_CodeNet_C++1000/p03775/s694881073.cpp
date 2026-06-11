#include <bits/stdc++.h>
using namespace std;
int Decimal(int N){
  int num=0;
  while(N!=0){
    N=N/10;
    num++;
  }
  
  return num;
}

    
int main(){
  long N; //Nの数
  long B=1; //AとBの数の入れ物を用意
  
  /////入力部/////
  cin >> N;
  
  int ans=Decimal(N); //1の時の値
  
  for (long A=2;A*A<=N;A++){
    if(N%A == 0){
      B = N/A;
      if(ans >Decimal(B))ans = Decimal(B);
    }
  }
  cout<<ans<<endl;
}

        
  
  
  
