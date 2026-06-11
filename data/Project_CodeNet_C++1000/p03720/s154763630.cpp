#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int M, N;
  cin >> M >> N;
  vector<int> city(M);
  vector<int> road(2*N);
  
  for (int i =0; i< 2*N ; i++){
    cin >> road.at(i);
    city.at(road.at(i)-1)++;
  }
  
  for (int i=0; i< M; i++){
    cout << city.at(i) << endl;
  }
}
