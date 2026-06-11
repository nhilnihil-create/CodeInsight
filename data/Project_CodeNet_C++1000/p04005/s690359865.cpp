#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a,b,c;
  cin>>a>>b>>c;
  if(a%2==0||b%2==0||c%2==0){
    cout<<"0"<< endl;
    return 0;
  }
  else{
    if(a*b<=b*c&&a*b<=a*c){
      cout<<a*b<< endl;
      return 0;
    }
    if(a*c<=b*c&&a*c<=a*b){
      cout<<a*c<< endl;
      return 0;
    }
    if(b*c<=a*c&&b*c<=a*b){
      cout<<b*c<< endl;
    }
  }
}