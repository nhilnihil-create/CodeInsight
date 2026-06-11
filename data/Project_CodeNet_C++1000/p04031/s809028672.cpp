#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  
 ll n,i,j=0,sm1=0,sm2=0,k;
 
 cin>>n;
 int a[n];
 for(i=0;i<n;i++)
 {
     cin>>a[i];
     j+=a[i];
 }
 k=j/n;
 j=ceil(j/(float)n);
 for(i=0;i<n;i++)
 {
     sm1+=(j-a[i])*(j-a[i]);
     sm2+=(k-a[i])*(k-a[i]);
 }
 cout<<min(sm1,sm2);
}