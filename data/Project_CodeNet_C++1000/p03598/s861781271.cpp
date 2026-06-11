#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int N,K,x;
 int L=0;
 cin>>N>>K;
 for(int i=0;i<N;i++) {
   cin>>x;
   if(x<=(K-x)) 
     L+=x*2;
   else
     L+=(K-x)*2;
 }
  cout<<L<<endl;
}