#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll n;cin >>n;
    vector<ll>a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    ll ans=0;
    for (int i = 0; i < n;) {
        if(i==n-1){
            ans+=a[i]/2;
            i++;
        }
        else if(a[i]%2==1&&a[i+1]%2==1){
            ans+=(a[i]+a[i+1])/2;
            a[i]=a[i+1]=0;
            i+=2;
        }
        else if(a[i]%2==0&&a[i+1]%2==0){
            ans+=(a[i]+a[i+1])/2;
            a[i]=a[i+1]=0;
            i+=2;
        }
        else if(a[i]%2==0&&a[i+1]%2==1){
            ans+=a[i]/2;
            a[i]=0;
            i++;
        }
        else if(a[i]%2==1&&a[i+1]%2==0){
            if(a[i+1]==0){
                ans+=a[i]/2;
                i+=2;
            }
            else {
                a[i]--;a[i+1]--;
                ans++;
                ans+=a[i]/2;
                i++;
            }
        }
    }
    cout <<ans <<endl;
    return 0;
}