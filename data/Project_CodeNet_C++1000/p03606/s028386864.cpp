#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int R = N;

  for(int i = 0; i < N; i++){
    int l, r;
    cin >> l >> r;
    R += r - l;
//    while(l <= r){
 //     R++;
  //    l++;
   // }
  }
  cout << R << endl;
}