#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<pair<int,int>>ab(n);
  for(int i=0; i<n; i++){
    cin >> ab[i].first >> ab[i].second;
  }
  sort(ab.rbegin(),ab.rend());
  cout << ab[0].first + ab[0].second << endl;
  return 0;
}