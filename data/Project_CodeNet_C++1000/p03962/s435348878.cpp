#include <bits/stdc++.h>
using namespace std;
const int64_t INF=999999999;

int main() {
   int a,b,c;
   cin>>a>>b>>c;
   if(a!=b&&b!=c&&a==c){cout<<2<<endl;}
   if(a!=b&&b!=c&&a!=c){cout<<3<<endl;}
   if(a==b&&b==c){cout<<1<<endl;}
   if(a!=b&&b==c){cout<<2<<endl;}
   if(a==b&&b!=c){cout<<2<<endl;}
   
return 0;}