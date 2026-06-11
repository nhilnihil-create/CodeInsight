#include <bits/stdc++.h>
using namespace std;
long long LCM(long long a,long long b);
long long ans=1;
int main(){
    int n;
    cin>>n;
    long long t[n+2]={};
    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    for(int i=0;i<n;i++){
        ans=LCM(t[i],ans);
    }
    cout<<ans<<endl;
    return(0);

}
long long LCM(long long a,long long b){
    return a/__gcd(a,b)*b;
}