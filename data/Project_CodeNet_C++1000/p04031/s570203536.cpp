#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  cin>>a.at(0);
  int g=a.at(0);
  int l=a.at(0);
  for(int i=1;i<n;i++){
    cin>>a.at(i);
    g=max(g,a.at(i));
    l=min(l,a.at(i));
  }
  int m=(g-l)*(g-l)*n;
  for(int x=l;x<=g;x++){
    int c=0;
    for(int i=0;i<n;i++)
      c+=(a.at(i)-x)*(a.at(i)-x);
    m=min(m,c);
  }
  cout<<m<<endl;
}