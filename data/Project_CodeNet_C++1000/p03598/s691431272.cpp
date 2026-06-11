#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k;
  cin >> n >> k;
  vector<int> num(n);
  for(int i=0;i<n;i++)
    cin >> num.at(i);
  int distance=0;
  for(int i=0;i<n;i++){
    if( num.at(i) > k - num.at(i) )
      distance += (k - num.at(i)) * 2;
    else
      distance += 2 * num.at(i);
  }
  cout << distance << endl;
    
}