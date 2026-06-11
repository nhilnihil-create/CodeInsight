#include <bits/stdc++.h>
using namespace std;
const int INF=999999999;

int main() {
 int A,B;
 cin>>A>>B;
 if(A==1){A=14;}
 if(B==1){B=14;}
 if(A>B){cout<<"Alice"<<endl;}
 else if(A<B){cout<<"Bob"<<endl;}
 else if(A==B){cout<<"Draw"<<endl;}
 return 0;}