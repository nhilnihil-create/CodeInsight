#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  
  vector<int> x(n,1);
  
  for(int i=2;i<=n;i++){
    int a=i;
    for(int j=2;j<=i;j++){
      while(a%j==0){
        a/=j;
        x.at(j-1)++;
      }
    }
  }
  
  long long int k=1;
  
  for(int i=0;i<n;i++){
      k*=x.at(i);
      k%=1000000007;
  }
  
  cout << k%1000000007 << endl;
}