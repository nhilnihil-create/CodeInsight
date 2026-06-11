#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main() {
  int n,m,p;
  long t,x,rem;
  vector<long> arr;
  cin >> n;
  while (n--)
  {
    cin >> t;
    arr.push_back(t);
  }
  cin >> m;
  while (m--)
  {
    cin >> p >> x;
    rem = arr[p-1];
    arr[p-1] = x;
    cout << accumulate(arr.begin(),arr.end(),0) << endl;
    arr[p-1] = rem;
  }
  return 0;
}