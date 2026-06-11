#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, K, x; 
  cin >> N >> K ;
  
  int sum=0;
  for (int i=0; i<N; i++){
    cin >> x;
    
    if((K - x) <= x)
      sum += 2 * (K - x);
    if((K - x) >  x)
      sum += 2 * x;
  }
  
  cout << sum << endl;
}
