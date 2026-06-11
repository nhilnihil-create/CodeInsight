#include <bits/stdc++.h>
using namespace std;
#include <math.h>
int main() {
 int N;
 cin>>N;
 vector<int>A(N);
 int countk=0;
 for(int i=0;i<N;i++){
     cin>>A[i];
     if(A[i]%2!=0){countk++;}
 }
 if(countk%2!=0){cout<<"NO"<<endl;}
 else{cout<<"YES"<<endl;}

 return 0;}