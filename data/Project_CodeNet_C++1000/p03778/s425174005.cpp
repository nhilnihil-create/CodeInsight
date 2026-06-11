#include<bits/stdc++.h>
using namespace std;
int main(){
  int w,x,y;
  cin>>w>>x>>y;
  cout<<max(0,abs(x-y)-w)<<endl;
}