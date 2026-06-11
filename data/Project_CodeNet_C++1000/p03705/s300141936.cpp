#include <iostream>
using namespace std;
typedef long long ll;
int main(){
  ll n,a,b;cin>>n>>a>>b;
  if(a>b){
    cout << '0'<<endl;
  }else{
    if(n==1){
      if(a==b){
        cout<< '1'<<endl;
      }else{
        cout << '0'<<endl;
      }
    }else{
      cout << (b-a)*(n-2)+1<<endl;
    }
  }
}
  