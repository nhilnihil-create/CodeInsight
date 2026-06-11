#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K;
  cin >> N >> K;
  int sum = 0;
  
  for(int i; i<N; i++){
    int x;
    cin >> x;
    int a, b;
    a = x;
    b = abs(x-K);
    if (a<b){
      sum += a*2;
    }
    else{
      sum += b*2;
    }
  }
  cout << sum << endl;
}