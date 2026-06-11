#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
   int n,t; cin>>n>>t;
   ll p=0;
   int arr[n]; for(int i=0;i<n;i++)cin>>arr[i];
   for(int i=1;i<n;i++){
    if(arr[i]-arr[i-1]<t){
        p=p+(arr[i]-arr[i-1]);
    }
    else p=p+t;
   } cout<<p+t;
}
