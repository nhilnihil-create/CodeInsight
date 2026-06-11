#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  int a[n], b[100010]={};
  for(int i=0; i<n; i++) {
    cin >> a[i];
    b[a[i]]++;
    if(a[i]>0) b[a[i]-1]++;
    if(a[i]<n) b[a[i]+1]++;
  }
  cout << *max_element(b, b+100010) << endl;
  return 0;
}