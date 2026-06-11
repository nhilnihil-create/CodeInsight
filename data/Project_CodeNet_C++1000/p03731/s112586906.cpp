#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, time;
  cin >> n >> time;
  int t[n];
  cin >> t[0];
  int total = 0;
  for(int i = 0; i < n -1; i++){
    cin >> t[i + 1];
    total += min(time, t[i + 1] - t[i]);
  }
  cout << total + time << endl;
  return 0;
}