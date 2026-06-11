#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#include <vector>
#include <string>

using namespace std; using ll=long long; const int INF=1e9; using P=pair<int,int>;

int main() {
  int n; cin>>n;
  int p[n]; for(int i=0;i<n;i++) {cin>>p[i]; p[i]--;}
  int an=0;
  for(int i=0;i<n;i++) {
    if (i != n-1) {
      if (p[i] == i) swap(p[i], p[i+1]), an++;
    } else {
      if (p[i] == i) swap(p[i], p[i-1]), an++;
    }
  }
  cout<<an<<endl;
}