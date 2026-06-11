#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
/*
*/
int main() {
  int n, m;
  cin >> n >> m;
  int a[51], b[51];
  int r[51] = {0};
  for(int i = 0; i < m; i++){
    cin >> a[i] >> b[i];
    r[a[i]]++;
    r[b[i]]++;
  }
  for(int i = 1; i <= n; i++) cout << r[i] << endl;
  return 0;
}
