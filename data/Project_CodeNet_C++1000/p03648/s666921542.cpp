#include <iostream>

using namespace std;

int main(){
  int n = 50;
  long long a[50];
  int r;
  long long k, m;
  cin >> k;
  for (int i=0;i<n;i++) {
    a[i] = i;
  }
  m = k / n + 1;
  for (int i=0;i<n;i++) {
    a[i] += m;
  }
  r = n*m - k;
  for (int h=0;h<r;h++) {
    int max_index;
    long long max_a = -1;
    for (int i=0;i<n;i++) {
      if (a[i] > max_a) {
	max_a = a[i];
	max_index = i;
      }
      a[i]++;
    }
    a[max_index]--;
    a[max_index] -= n;
  }
  cout << n << endl;
  for (int i=0;i<(n-1);i++) {
    cout << a[i] << " ";
  }
  cout << a[n-1] << endl;
  return(0);
}
