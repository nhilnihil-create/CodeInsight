#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(n);
  vector<pair<int, int>> b(m);
  for(int i = 0; i < n; i++){
    cin >> a[i].first >> a[i].second;
  }
  for(int i = 0; i < m; i++){
    cin >> b[i].first >> b[i].second;
  }
  for(int i = 0; i < n; i++){
    long long record, ans = 1000000000000000;
    for(int j = 0; j < m; j++){
      long long count = 0;
      count += abs(a[i].first - b[j].first) + abs(a[i].second - b[j].second);
      if(ans > count) {
        record = j + 1; 
        ans = count;
      }
    }
    cout << record << endl;
  }
}