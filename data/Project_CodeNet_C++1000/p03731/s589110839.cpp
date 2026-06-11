#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

long long int gcd(long long int a,long long int b){
    if(a%b==0){
        return b;
    }
    else{
        return gcd(b,a%b);
    }
}
long long int fac(long long int n){
    if(n==0){
        return 1;
    }
    else{
        return n*(fac(n-1))%1000000007;
    } 
}

int main(){
    long long int n,k,ans=0;
    cin>>n>>k;
    vector<long long int>a(300000);
    for(int i=0;i<n;i++){
        cin>>a[i];
            }
    for(int i=0;i<n-1;i++){
        if(a[i+1]-a[i]>k){
            ans+=k;
        }
        else{
            ans+=a[i+1]-a[i];
        }
    }
    ans+=k;


    
    cout<<ans<<endl;
    return 0;
}