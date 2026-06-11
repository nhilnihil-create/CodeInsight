#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, r, s, Ans;
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> r >> s;
    Ans += s - r + 1;
  }
  cout << Ans << endl;
}
