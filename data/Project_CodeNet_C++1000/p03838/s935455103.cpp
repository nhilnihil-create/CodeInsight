//There are four possible cases both pos - neg etc
//both pos - x > y - two times change sign + abs(x-y)
//both pos - x<y - abs(x-y)
//both neg - x > y - abs(
//both neg - x<y - two times change sign + that thing
//x pos y neg - change to 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pos(ll x, ll y){
	if(y>=x)return abs(x-y);
  	return 2+abs(x-y);
}
ll neg(ll x,ll y){
	if(y>=x)return abs(x-y);
  	return 2+abs(x-y);
}
int main(){
	ll x,y;cin>>x>>y;
if(x==0){
    if(y>0)cout<<y;
    if(y<0)cout<<-y+1;
}
else if(y==0){
    if(x>0)cout<<x+1;
    else cout<<-x;
}
  else if(x>0 && y>0)cout<<pos(x,y);
  else if(x<0 && y<0)cout<<neg(x,y);
  else if(x<0 && y>0)cout<<min(neg(x,-y),pos(-x,y))+1;
  else if(x>0 && y<0)cout<<min(neg(-x,y),pos(x,-y))+1;
}