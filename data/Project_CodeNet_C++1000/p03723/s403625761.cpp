#include<bits/stdc++.h>

using namespace std;

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  if(a==b && b==c){
    if(a%2==0 && b%2==0 && c%2==0){
      cout<<-1<<endl;
      return 0;
    }
  }
  int count=0;
  while(1){
    if(a%2!=0 || b%2!=0 || c%2!=0){
      cout<<count<<endl;
      return 0;
    }
    int d=a;
    int e=b;
    int f=c;
    a=(e+f)/2;
    b=(d+f)/2;
    c=(d+e)/2;
    count++;
  }
}