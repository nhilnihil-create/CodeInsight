#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  
  long long count1 = 0;
  long long sum = 0;
  for (int i = 0; i < n; i++){
    if (i % 2){
      if (sum + a.at(i) > 0){
        sum += a.at(i);
      }
      else{
        count1 += 1 - (sum + a.at(i));
        sum = 1;
      }
    }
    else{
      if (sum + a.at(i) < 0){
        sum += a.at(i);
      }
      else{
        count1 += 1 + (sum + a.at(i));
        sum = -1;
      }
    }
  }
  
  long long count2 = 0;
  sum = 0;
  for (int i = 0; i < n; i++){
    if (!(i % 2)){
      if (sum + a.at(i) > 0){
        sum += a.at(i);
      }
      else{
        count2 += 1 - (sum + a.at(i));
        sum = 1;
      }
    }
    else{
      if (sum + a.at(i) < 0){
        sum += a.at(i);
      }
      else{
        count2 += 1 + (sum + a.at(i));
        sum = -1;
      }
    }
  }
  
  cout << min(count1, count2) << endl;
}
