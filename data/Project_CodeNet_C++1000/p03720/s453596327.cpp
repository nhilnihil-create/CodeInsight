#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, m;
  cin >> n >> m;
  
  vector<int> city(n);
  vector<int> road(2);
  
  for (int i = 0; i < m; i++) {
    cin >> road.at(0) >> road.at(1);
    city.at(road.at(0) - 1)++;
    city.at(road.at(1) - 1)++;
  }
  
  for (int i = 0; i < n; i++) {
    cout << city.at(i) << endl;
  }
}