#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    for(int i=0;i<n;i++){
        long long m=i,p=n-1-i;
        long long l,r;
        
        l = a - m*d + p*c;
        r = a - m*c + p*d;
        if(l<=b && b<=r){
            cerr<<m<<" "<<l<<" "<<r<<endl;
            cout<<"YES"<<endl;
            return 0;
        }

        
    }
    cout<<"NO"<<endl;
}