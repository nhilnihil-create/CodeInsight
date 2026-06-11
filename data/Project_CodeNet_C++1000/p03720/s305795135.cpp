#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, m;
  cin >> n >> m;
  
  vector<int> a(m);
  vector<int> b(m);
  vector<int> way(n);
  
  for(int i = 0; i < m; i++) cin >> a.at(i) >> b.at(i);
    
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(a.at(i) == j + 1) way.at(j)++;
      if(b.at(i) == j + 1) way.at(j)++;
    }
  }
  for(int i = 0; i < n; i++) cout << way.at(i) << endl;
}