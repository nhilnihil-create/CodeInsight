#include <bits/stdc++.h>
using namespace std;
const int64_t INF=9999999999999999;

int main() {
   int N;
   cin>>N;
   vector<int>A(N);
   for(int i=0;i<N;i++){
      cin>>A[i];
   }
   int countk=0;
   for(int i=0;i<N;i++){
   if(A[i]%2!=0){countk++;}
   }
   if(countk%2==0){cout<<"YES"<<endl;}
   else{cout<<"NO"<<endl;}
return 0;}