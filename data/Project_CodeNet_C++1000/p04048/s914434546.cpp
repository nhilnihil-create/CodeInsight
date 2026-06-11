#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fo(a,b) for(int a=0;a<b;a++)
 int wari(int a,int b) {
   if(a%b==0)
     return a/b;
   else
     return a/b+1;
 }
 int keta(int a){
  double b=a;
  b=log10(b);
  int c=b;
  return c+1;
 }
 int souwa(int a){
  return a*(a+1)/2;
 }
 int lcm(int a,int b){
  int d=a,e=b,f;
  if(a<b)
    swap(a,b);
  int c,m=1;
  while(m){
    c=a%b;
    if(c==0){
       f=b;
      m--;
    }
    else{
      a=b;
      b=c;
 }
  }
  return d*e/f;
    }
  int gcm(int a,int b){
      int d=a,e=b,f;
  if(a<b)
    swap(a,b);
  int c,m=1;
  while(m){
    c=a%b;
    if(c==0){
       f=b;
      m--;
    }
    else{
      a=b;
      b=c;
 }
  }
  return f;
  }
signed main(){
  int a,b;
  cin>>a>>b;
  int c=gcm(a,b);
  cout<<3*(a-c)<<endl;
}
  /*while(c){
  if(a%2==0){
    d++;
    a/=2;
  }
  else
    c=0;
  }
  
    cout<<3*a/2<<endl;
      else
  cout<<3*a-3<<endl;
}*/
