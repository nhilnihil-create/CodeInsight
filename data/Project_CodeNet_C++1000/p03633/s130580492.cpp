#include<bits/stdc++.h>
using namespace std;
/*bool is(long long a){
    if(a==2) return true;
    if(a<=1||a%2==0) return false;
    for(int i=3;i*i<=a;i+=2){
        if(a%i==0) return false;
    }
    return true;
}*/
long long gcd(long long a,long long b){
    if(b==0) return a;
    return gcd(b,a%b);
}
long long lcm(long long a,long long b){
    return(a/gcd(a,b)*b);
}
int main(){
    int n;
    cin>>n;
    long long z[n];
    cin>>z[0];
    for(int i=1;i<n;i++){
        cin>>z[i];
        z[i]=lcm(z[i-1],z[i]);
    }
    cout<<z[n-1]<<'\n';
    return 0;
}