#include<bits/stdc++.h>
using namespace std;

int main(){

 int N, K;
 cin >> N >> K;
  
 int sum = 0;
 
 for(int i = 0; i < N; i++){
  int xi;
  cin >> xi;
   
  if(xi < K - xi){
   sum += 2 * xi;
  }
  
  else{
   sum += 2 * (K - xi);
  }
 }
 cout << sum << endl;
}