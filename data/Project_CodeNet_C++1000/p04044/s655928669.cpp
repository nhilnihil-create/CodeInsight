#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define for(i,a,b) for(int i = a;i<b;i++)


int main()
{
 
 int n,l;
 cin>>n>>l;
 string a[n];
 for(i,0,n) cin>>a[i];
 for(i,0,n-1){
     for(j,i+1,n){
         if(a[i]>a[j]){
             swap(a[i],a[j]);
         }
     }
 }
 for(i,0,n) cout<<a[i];
return 0;
   
}