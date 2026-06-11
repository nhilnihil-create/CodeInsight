#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin >> a>>b>>c;
  int count=3;
  if(a==b &&a==c){
    cout << 1;
  }else if (a==b || a==c || b==c){
    cout << 2;
  }else{
    cout << 3;
  }
}
  
  
