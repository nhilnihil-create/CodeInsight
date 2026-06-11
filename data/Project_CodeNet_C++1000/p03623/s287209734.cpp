#include <bits/stdc++.h>
using namespace std;
const int64_t INF=999999999;

int main() {
   int x,a,b;
   cin>>x>>a>>b;
   if(abs(x-a)>abs(x-b)){cout<<"B"<<endl;}
   if(abs(x-a)<abs(x-b)){cout<<"A"<<endl;}
return 0;}