#include <bits/stdc++.h>
using namespace std;

int main() {  
  int n,m; cin>>n>>m;
  vector<int> sum(n);
  vector<int> a(2);
  for(int i=0;i<m;i++){
    cin>>a[0]>>a[1];
    sum[a[0]-1]++;
    sum[a[1]-1]++;
  }
  for(int j=0;j<n;j++)
    cout<<sum[j]<<endl;
}