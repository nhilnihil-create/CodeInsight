#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin >> n;
  vector<int> p(n),a(n),b(n);
  for(int i=0;i<n;i++){
    cin >> p[i];
    a[p[i]-1]=(n+5)*p[i];
    b[p[i]-1]=(n+5)*(n+1-p[i])+i;
  }
  for(int i=0;i<n;i++){
    cout << a[i] << " ";
  }
  cout << endl;
  for(int i=0;i<n;i++){
    cout << b[i] << " ";
  }
  cout << endl;
}