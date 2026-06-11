#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

bool check(int a[],int n){
    if(n%2==0){
        int j=1,i=0;
        while(i<n){
            if(i+1==n)return 0;
            if(a[i]!=a[i+1])return 0;
            else{
                if(a[i]!=j)return 0;
            }
            i+=2;j+=2;
            if(i>=n)break;
        }
    }
    else{
        if(a[0]!=0)return 0;
        int j=2,i=1;
        while(i<n){
            if(i+1==n)return 0;
            if(a[i]!=a[i+1])return 0;
            else{
                if(a[i]!=j)return 0;
            }
            i+=2;j+=2;
            if(i>=n)break;
        }
    }
    return 1;
}

int answer(int n){
    int ans=1;
    while(n--){
        ans=((ans%mod)*(2%mod))%mod;
    }
    return ans%mod;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    if(check(a,n)){
        cout<<answer(n/2);
    }
    else cout<<0;
}