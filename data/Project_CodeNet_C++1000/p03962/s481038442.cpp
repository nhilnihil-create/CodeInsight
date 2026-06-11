#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin>>a>>b>>c;
  int count=1;
  if(a==b){
    count++;
    if(b==c){
      count++;
    }
  }
  else if(a==c){
    count++;
  }
  else if(b==c){
    count++;
  }
  cout<<4-count<<endl;
}