#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  if(a<b){
    cout << a*c << endl;
  }else{
    int n=a-b;
    cout << b*c+n*d << endl;
  }
}