#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  long long div = pow(10,9) + 7;
  long long tmp = 1;
  for(int i=1;i<=N;i++){
    tmp = (i*tmp) % div;
  }
  cout << tmp << endl;
}