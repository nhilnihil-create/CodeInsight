#include <bits/stdc++.h>
using namespace std;

//B - Collecting Balls (Easy Version)
int main() {
  int n, k;
  cin >> n >> k;
  
  int sum = 0;
  vector<int> x(n);
  for (int i = 0; i < n ; i++){
    cin >> x.at(i);
    sum += min(x.at(i) , k-x.at(i))*2;
  }
  cout << sum << endl;
}
