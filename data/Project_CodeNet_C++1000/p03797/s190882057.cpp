#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,m;
  cin>>n>>m;
  cout<<min(n,m/2)+(m-min(n,m/2)*2)/4<<endl;
}