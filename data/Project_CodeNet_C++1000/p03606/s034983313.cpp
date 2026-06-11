#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int a[2];
  int sum=0;
  for(int i=0;i<N;i++){
    cin >> a[0] >> a[1];
    sum += (a[1]-a[0]+1);
  }
  cout << sum << endl;
}