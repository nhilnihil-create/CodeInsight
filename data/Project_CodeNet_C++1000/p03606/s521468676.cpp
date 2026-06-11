#include<bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  int sum = 0;

  int minNum,maxNum;
  for(int i = 0; i < n; ++i){
    cin >> minNum >> maxNum;
    sum += maxNum - minNum +1;
  }
  cout << sum << endl;
}