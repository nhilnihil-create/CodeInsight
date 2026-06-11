#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<cstring>
using namespace std;
long long int mod = 1e9 + 7;
template <class T>
void inputV(vector<T> &x, int n){
  for(int i=0; i<n; i++) cin >> x[i];
}

int main() {
  int n, t;
  cin >> n >> t;
  if(t%2==1) t--;
  vector<int> a(n);

  for(int i=0; i<n; i++) cin >> a[i];
  int p = a[0];
  int d = 0;
  map<int, int> mp;
  for(int i=0; i<n; i++){
    if(p > a[i]){
      p = a[i];
    }
    d = max(a[i]-p, d);
    mp[a[i]-p]++;
    cerr << a[i]-p << " " << mp[a[i]-p] << endl;
  }
  cerr << d << endl;
  int r = d * t/2;

  cout << mp[d] << endl;

  return 0;
}



//
