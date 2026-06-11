#include<bits/stdc++.h>     //11monme
using namespace std;
long long LCM(long long a,long long b);
signed main(){
    int n;
    cin>>n;
    long long t[n+2];
    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    long long sum=t[0];
    for(int i=0;i<n;i++){
        sum=LCM(sum,t[i]);
    }
    cout<<sum<<"\n";
    return(0);
}
long long LCM(long long a,long long b){
    return(a/__gcd(a,b)*b);
}