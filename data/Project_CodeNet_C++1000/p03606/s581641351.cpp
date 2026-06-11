#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
  
  int n;
  cin >> n;
  
  bool arr[100000] = {0};
  for(int i = 0; i < n; i++) {
    int start, end;
    cin >> start >> end;
    for(int j = start - 1; j < end; j++) {
      arr[j] = true;
    }
  }
  
  int n_people = accumulate(&arr[0], &arr[100000], 0L);
  cout << n_people << endl;
}
