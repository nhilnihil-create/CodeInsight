#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  
  vector<int> x(n);
  
  for(int i=2;i<=n;i++){
    int a=i;
    for(int j=2;j<=i;j++){	//iを素因数分解
      while(a%j==0){
        a=a/j;
        x.at(j-1)++;
      }
    }
  }
  
  long long int p=1;
   
  for(int i=0;i<n;i++){
    p*=x.at(i)+1;
    p%=1000000007;
  }
  
  cout << p%1000000007 << endl;
}