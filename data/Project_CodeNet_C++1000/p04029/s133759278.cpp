#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  cin >> N;

  int total = 0;
  int candy = 1;
  for (int i = 1; i <= N; i++){
    total += candy;
    candy += 1;
  }
  cout << total << endl;
}