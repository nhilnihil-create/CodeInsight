#include<bits/stdc++.h>
using namespace std;

using LL = long long;

int main(){
  LL N;
  cin>> N;
  
  for(LL i=sqrt(N);i>0;i--){
    if(N%i==0){
      i=N/i;
      int count=0;
      while(i>0){
        i/=10;
        count++;
      }
      cout << count << endl;
      return 0;
    }
  }
}