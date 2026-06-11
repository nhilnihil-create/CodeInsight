#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t n, k;
  cin >> n >> k;
  pair<int, int> a[n];
  for(int i=0; i<n; i++)
    cin >> a[i].first >> a[i].second;
  sort(a, a+n);
  for(int i=0; i<n; i++){
    k-=a[i].second;
    if(k<=0){
      cout << a[i].first;
      return 0;
    }
  }
}
