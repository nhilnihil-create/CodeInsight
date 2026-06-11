#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  int ans = 0;
  cin >> N;
  float ave = 0;
  vector<int> a(N);
  for(int i = 0; i < N; i++){
    cin >> a.at(i);
    ave += a.at(i);
  }
  ave = round(ave / N);
  
  for(int i = 0; i < N; i++)
    ans += (a.at(i) - ave) * (a.at(i) - ave);
  cout << ans << endl;
}
