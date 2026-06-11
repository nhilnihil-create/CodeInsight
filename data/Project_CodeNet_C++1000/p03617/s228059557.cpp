#include <bits/stdc++.h>
using namespace std;

int main() {
    long long q,h,s,d;cin>>q>>h>>s>>d;
    long long low=min(8*q,min(4*h,min(2*s,d)));
    long long n;cin>>n;
    if(n==1){
        long long one=min(s,min(h*2,q*4));
        cout<<one<<endl;
    }else{
        long long price;
        if(n%2==0) price=low*n/2;
        else price=low*(n-1)/2;
        n=n%2;
        if(n==0) cout<<price<<endl;
        else{
            long long rest_min=min(q*4,min(h*2,s));

            price+=rest_min;
            cout<<price<<endl;
        }
    }

}