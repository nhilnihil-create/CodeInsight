#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#include <vector>
#include <string>

using namespace std; using ll=long long; const int INF=1e9; using P=pair<int,int>;

int main() {
  int n; cin>>n;
  int a[2]={};
  for(int i=0;i<n;i++) {
    int b; cin>>b; a[b%2]++;
  }
  if (a[1]%2) cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
}