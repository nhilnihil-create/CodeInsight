#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t x,y;
  cin>>x>>y;
  if(x*2>=y) cout<<y/2<<endl;
  else{
    y-=x*2;
    cout<<x+y/4<<endl;
  }
}