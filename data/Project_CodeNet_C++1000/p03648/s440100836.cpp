#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli>> mat;
typedef vector<unordered_map<lli,lli>> graph;

lli k;
lli n;
vll a;

int main(){
  cin >> k;
  n = 50;
  a = vll(n);
  for(lli i = 0;i < n;i++) a[i] = i;
  for(lli i = 0;i < n;i++){
    a[i] += k/n;
  }
  k %= n;
  for(lli i = 0;k > 0;k--,i++){
    a[i] += n;
    for(lli j = 0;j < n;j++){
      if(j != i) a[j]--;
    }
  }
  cout << n << endl;
  for(lli i = 0;i < n-1;i++){
    cout << a[i] << " ";
  }
  cout << a[n-1] << endl;
  return 0;
}
