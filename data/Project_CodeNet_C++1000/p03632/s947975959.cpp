#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d,time;
  cin >>a>>b>>c>>d;
  if(a>=d||b<=c){
    time=0;
  }else if(a<=c){
    time=min(b-c,d-c);
  }else{
    time=min(b-a,d-a);
  }
  cout << time << endl;
}