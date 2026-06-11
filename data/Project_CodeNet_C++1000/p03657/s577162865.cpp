#include <bits/stdc++.h>
using namespace std;
#include <math.h>
const int64_t INF=9999999999999999;

int main() {
 int A,B;
 cin>>A>>B;
 if(A%3==0||B%3==0||(A+B)%3==0){cout<<"Possible"<<endl;}
 else{cout<<"Impossible"<<endl;}
return 0;}