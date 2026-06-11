#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  int sum = 0;
  for (int i = 0;i < n;i++) {
    int x;
    cin >> x;
    int a = 0;
    if(x >= k) a = x - k;
    else a = k - x;
    if(x >= a){
      sum += (a * 2);
    }
    else sum += (x * 2);
  }
  cout << sum << endl;
}
