#include<bits/stdc++.h>
using namespace std;
int main() {
  int a[12]={0,2,0,1,0,1,0,0,1,0,1,0};
  int b,c;
  cin>>b>>c;
  if(a[b-1]==a[c-1]) {
    cout<<"Yes"<<endl;
  }
  else {
    cout<<"No"<<endl;
  }
  return 0;
}
