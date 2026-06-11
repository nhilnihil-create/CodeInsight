#include <bits/stdc++.h>
using namespace std;
const int64_t INF=999999999;

int main() {
   int X,A,B;
   cin>>X>>A>>B;
   if(A>=B){cout<<"delicious"<<endl;}
   else if(B-A<=X){cout<<"safe"<<endl;}
   else{cout<<"dangerous"<<endl;}
return 0;}