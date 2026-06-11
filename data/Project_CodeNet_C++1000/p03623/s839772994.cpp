#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,a,b;
  cin>>x>>a>>b;
  int da=abs(x-a);
  int db=abs(x-b);
  if(da<=db){
    cout<<"A"<<endl;
  }
  else{
    cout<<"B"<<endl;
  }  
}
