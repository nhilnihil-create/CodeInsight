#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull cbs(int n, int p) {
  vector<vector<ull>> v(n+1,vector<ull>(n+1,0));
  for(int i = 0;i < n+1; i++) {
    v[i][0]=1;
    v[i][i]=1;
  }
  for(int i = 1;i < n+1;i++) {
    for(int j = 1;j < i;j++) v[i][j]=(v[i-1][j-1]+v[i-1][j]);
  }
  ull sum = 0;
  for(int i = p;i < n+1;i+=2) sum += v[n][i];
  return sum;
}
int main() {
  int n, p, x, a = 0, b = 0;
  cin >> n >> p;
  for(int i = 0;i < n;i++) {
    cin >> x;
    if(x % 2 == 0) a++;
    else b++;
  }
  cout << (ull)pow(2, a)*cbs(b, p) << endl;
}