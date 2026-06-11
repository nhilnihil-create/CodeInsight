#include <bits/stdc++.h>
using namespace std;
int main(){
  int a;
  cin>> a;
  int s=a%10;
  int b=a/10%10;
  if(s==9||b==9){
    cout <<"Yes"<< "\n";
  }else{
    cout <<"No"<<"\n";
  }
}