#include <bits/stdc++.h>
using namespace std;

int pow(int i, int n){
  int ans = 1;
  for(int j=0; j<n;j++){
    ans *=i;
  }
  return ans;
}

int main(){
  int N;
  cin >> N;
  
  int count = 0;
  for(int i=0; i<N; i++){
    if(N >= pow(2,i)){
      count = i;
    }else{
      break;
    }
  }
  
  cout << pow(2,count) << endl;
}