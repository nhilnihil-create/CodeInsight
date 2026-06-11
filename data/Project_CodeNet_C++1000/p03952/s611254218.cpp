#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fo(a,b) for(int a=0;a<b;a++)
#define Sort(a) sort(a.begin(),a.end())
#define rev(a) reverse(a.begin(),a.end())
#define fi first
#define se second
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
 bool prime(int a){
   if(a<2)
     return false;
   else if(a==2)
     return true;
   else if(a%2==0)
     return false;
   double b=sqrt(a);
    for(int i=3;i<=b;i+=2){
      if(a%i==0){
        return false;
      }
    }
   return true;
 }
signed main(){
  int a,b,d;
  cin>>a>>b;
  if(b==1||b==2*a-1)
    cout<<"No"<<endl;
  else{
    cout<<"Yes"<<endl;
    vector<int> c(2*a-1);
    d=2*a-1;
    fo(i,d)
      c[i]=d-i;
    if(b>a){
      swap(c[a-1],c[0]);
      swap(c[a],c[d-b]);
      swap(c[a-2],c[d-1]);
    }
    else if(b<a){
      rev(c);
      swap(c[a-1],c[0]);
      swap(c[a],c[b-1]);
      swap(c[a-2],c[d-1]);
    }
    fo(i,d)
      cout<<c[i]<<endl;
  }
}