#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long> a(n*3);
  for(int i = 0; i <n*3; i++) cin >> a[i];

  sort(a.begin(), a.end()); 
  vector<long> mid(n);
  for(int i = 0; i < n; i++) {
    mid[i] = a[3*n -2 -i*2];
  }

  cout << accumulate(mid.begin(), mid.end(), 0L) << endl;
 return 0;
}
