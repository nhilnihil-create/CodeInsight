#include <bits/stdc++.h>
#define MAX 100000000000000
using namespace std;
int main(void)
{
  int n, a[200000];
  long sum = 0, st = 0, mst = MAX;
  cin >> n;
  for(int i = 0; i != n; i++){
    cin >> a[i];
    sum += a[i];
  }
  for(int i = 0; i != n - 1; i++){
    st += a[i];
    long k = abs(sum - st * 2);
    if(k < mst) mst = k;
  }
  cout << mst << endl;
  return 0;
}