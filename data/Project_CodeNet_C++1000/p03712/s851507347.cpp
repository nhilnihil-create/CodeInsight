#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w; cin>>h>>w;
  vector<string> a(h);
  for(int i=0;i<h;i++)
    cin>>a[i];
  
  for(int j=0;j<w+2;j++)
    cout<<'#';
  cout<<endl;
  for(int k=0;k<h;k++)
    cout<<'#'<<a[k]<<'#'<<endl;
  for(int l=0;l<w+2;l++)
    cout<<'#';
  cout<<endl;
  
}