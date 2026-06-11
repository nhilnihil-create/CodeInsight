#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll a,b;cin>>a>>b;
  if(a==0||b==0){
    cout<<"Zero\n";
    return 0;
  }
  if((a>0&&b<0)||(a<0&&b>0)){
    cout<<"Zero\n";
    return 0; 
  }
  if(a>0&&b>0){
    cout<<"Positive\n";
    return 0;
  }
  if(a<0&&b<0){
    switch((b-a)%2){
      case 0:
        cout<<"Negative\n";
        break;
      case 1: 
        cout<<"Positive\n";
        break;
    }
  }
}