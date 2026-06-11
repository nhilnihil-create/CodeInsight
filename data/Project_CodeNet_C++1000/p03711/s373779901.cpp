#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y;cin>>x>>y;
  set<int>s={4,6,9,11};
  x==2?x=0:s.count(x)?x=1:x=2;
  y==2?x=0:s.count(y)?y=1:y=2;
  cout<<(x-y?"No":"Yes");
}