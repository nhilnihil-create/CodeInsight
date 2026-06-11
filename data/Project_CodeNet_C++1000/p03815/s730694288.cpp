#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n;cin>>n;
  int64_t ans=n/(11);
  int64_t asn2=ans*2;
  if(11*ans<n){
    if(11*ans+6>=n)asn2++;
    else if(11*ans+11>=n)asn2+=2;
  }
  cout <<asn2<<endl;
}