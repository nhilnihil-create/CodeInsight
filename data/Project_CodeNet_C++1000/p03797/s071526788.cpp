#include<iostream>
using namespace std;
typedef long long ll;
int main(){
  ll a,b;
  while(cin>>a>>b){
    if(a<<1 <= b) cout<< (b-a*2)/4+a <<endl;
    else cout<< (b>>1) <<endl;
  }
  return 0;
}