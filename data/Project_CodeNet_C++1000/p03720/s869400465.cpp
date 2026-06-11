#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, m;
  cin >>n >>m;
  
  int roadb, roade;
  vector<int> city(n, 0);

  for (int i = 0; i < m; i++) {
    cin >> roadb >> roade;
    city[roadb-1] ++;
    city[roade-1] ++;
  }
    
  for (int x : city)
    cout << x << endl;
}