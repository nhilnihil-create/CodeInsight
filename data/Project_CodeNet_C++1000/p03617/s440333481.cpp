#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    long long  q,h,s,d;
    cin>>q>>h>>s>>d;
    long long p1,p2;
    p1=min(4*q,min(2*h,s));
    p2=min(2*p1,d);
    long long n;
    cin>>n;
    long long ans;
    if(n%2==0)ans=p2*n/2;
    else ans=p1+(n/2)*p2;
    cout<<ans<<endl;
    return 0;
}