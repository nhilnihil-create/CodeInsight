#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t x,y;
  cin>>x;
  y=x/11*2;
  x%=11;
  if(1<=x&&x<=6) y++;
  else if(x>6) y+=2;
  cout<<y<<endl;
}