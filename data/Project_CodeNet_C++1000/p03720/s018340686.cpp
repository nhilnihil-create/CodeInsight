#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  vector<int> cities(N, 0);
 
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    cities[a - 1]++;
    cities[b - 1]++;    
  }
  
  for (auto i = cities.begin(); i != cities.end(); i++) {
	cout << *i << endl;
  }
}
