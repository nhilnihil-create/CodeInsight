#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, cnt=0;
  cin >> N;
  for(int i=N; i>=1; i--){
    cnt = cnt + i;
  }
  cout << cnt;
}