#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  long long int sum = 0;
  cin >> S;
  int n = S.size() - 1;
  
  for(int bit = 0; bit < (1<<n); bit++){
    long long int a = 0;
    for(int i=0; i < n+1;i++){
      a = a*10 + (int)S[i] - 48;
  	  //cout << a << endl;
      
      if(i==n)
        sum += a;
      else if((bit & (1 << i))){
        sum += a;
        a = 0;
      }
    }
  }
  cout << sum << endl;
}