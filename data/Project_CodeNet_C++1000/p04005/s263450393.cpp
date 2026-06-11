#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int64_t> A(3);
  for(int64_t &i:A)
    cin>>i;
  sort(A.begin(),A.end());
  if(A[0]%2==0 || A[1]%2==0 || A[2]%2==0)
    cout<<0<<endl;
  else
    cout<<A[0]*A[1]<<endl;
}