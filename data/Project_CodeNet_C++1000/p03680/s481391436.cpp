#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  vector<int> a(n + 1);
  for(int i = 1; i <= n; i++)
    cin >> a.at(i);
  int button = 1;
  int cnt = 1;
  for(int i = 1; i <= 100000; i++){
    if(a.at(button) == 2){
      cout << cnt;
      return 0;
    }
    button = a.at(button);
    cnt++;
  }
  cout << -1;
}