#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> l(n);
  vector<int> r(n);
  for(int i=0;i<n;i++)
    cin>>l.at(i)>>r.at(i);
  int c=0;
  for(int x=1;x<=100000;x++){
    for(int i=0;i<n;i++){
      if(l.at(i)<=x&&x<=r.at(i)){
        c++;
        break;
      }
    }
  }
  cout<<c<<endl;
}