#include<bits/stdc++.h>
 using namespace std;

 int main()
 {
     int n,x,flag=0;
     cin>>n;
     while(n){
        if(n%10==9){flag=1;}
        n/=10;
     }
    if(flag==1){cout<<"Yes"<<endl;}
    else {cout<<"No"<<endl;}
 }
