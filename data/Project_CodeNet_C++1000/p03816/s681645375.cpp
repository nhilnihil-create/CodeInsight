#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  map<int,int> c;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    c[a]++;
  }
  int r=0;
  for(auto x:c)
    r=abs(r-(x.second-1));
  cout<<c.size()-r%2<<endl;
}