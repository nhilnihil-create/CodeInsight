#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int K;
  cin >> N >> K;
  int x;
  x = 0;
  for (int i=0; i < N; i++){
    int a;
    cin >> a;
    int b = K - a;
    if (b > a){
    x += 2*a;
    }else{
      x += 2*b;
    }
  }
    cout << x << endl;
}