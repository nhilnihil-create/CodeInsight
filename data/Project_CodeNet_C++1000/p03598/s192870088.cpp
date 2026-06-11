#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k, sum=0;
  cin >> n >> k;
  
  for(int i=0, x; i < n; i++){
    cin >> x;
    if((k - x) < x){
      sum += (k - x) * 2;
    }else{
      sum += x * 2;
    }
  }
  cout << sum << endl;
}