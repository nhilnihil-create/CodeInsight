#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N, i, a;
  cin >> N;
  vector<int> num(N);
  for(i=0; i<N; i++){
    cin>>a;
    if(a%4==0){
      num[0]++;
    }else if(a%2==0){
      num[1]++;
    }else{
      num[2]++;
    }
  }
  
  if(num[1]==0){
    if(num[0]+1>=num[2]){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }else{
    if(num[0]>=num[2]){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }    
  }
  
  return 0;
}