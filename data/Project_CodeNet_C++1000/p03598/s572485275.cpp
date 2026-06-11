#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K;
  cin >> N >> K;
  int S = 0;
  for(int i = 0; i < N ; i++){
    int l;
    cin >> l;
    if ( l - abs(l-K) < 0){
      S += 2*l;
    }
    else{
      S += 2*abs(l-K);
    }
   // cout << i+1 <<":"<< S << endl;
  }
  cout << S << endl;
}
