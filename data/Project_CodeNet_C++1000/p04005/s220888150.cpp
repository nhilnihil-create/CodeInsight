#include<iostream>
using namespace std;
typedef long long ll;

int main(){
	ll a,b,c;
  cin>>a>>b>>c;
  if(a%2==0||b%2==0||c%2==0){
    cout<<0<<endl;
    return 0;
  }else{
    cout<<min(min(a*b,b*c),c*a)<<endl;
    return 0;
  }
}