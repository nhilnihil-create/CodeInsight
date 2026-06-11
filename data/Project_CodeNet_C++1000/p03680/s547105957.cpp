#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
   for (int i = 0; i < N; i++) {
     cin >> vec.at(i);
   }
  
  int a = vec.at(0); // ボタン1の番号
  int x = 1; // ボタンを押す回数
  
   for (int i = 0; i < N; i++) {
     if (vec.at(0) == 2){
       break;
     }
     else if (vec.at(a-1) == 2){
       x ++;
       break;
     }
     else if(x == N){
       x = -1;
       break;
     }
     else{
       x ++;
       a = vec.at(a-1);
     }
   }
  cout << x << endl;
}