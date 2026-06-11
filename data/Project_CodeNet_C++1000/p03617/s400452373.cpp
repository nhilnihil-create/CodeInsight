#include<iostream>
using namespace std;

int main(){
    long long q,h,s,d,n;
    cin>>q>>h>>s>>d>>n;
    long long m=min(4*q,min(2*h,s));
    long long ans=min(m*n,n/2*d+n%2*m);
    cout<<ans<<endl;
}