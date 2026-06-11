#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    long long n,x;
    cin>>n>>x;
    long long a=x;
    long long b=n-x;
    if(a<b)
    swap(a,b);
    while(b !=0){
        long long x=a;
        a=b;
        b=x%b;
        if(a<b)
        swap(a,b);
        
    }
    
    cout<<3*(n-a);
    return 0;
    
}
