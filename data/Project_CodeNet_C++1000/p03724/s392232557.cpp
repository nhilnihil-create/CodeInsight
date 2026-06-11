#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n,m; cin>>n>>m;
  vector<int> p(n+1);
  for(int i=0;i<m;i++) {
    int a,b; cin>>a>>b; a--;b--;
    p[a]++; p[b]++;
  }
  for(int i=0;i<n;i++) {
    if (p[i]%2 == 1) {
      cout<<"NO"<<endl; return 0;
    }
  }
  cout<<"YES"<<endl;
}