#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n;cin>>n;
    ll a[n],t[n];
    rep(i,n){
        cin>>a[i]>>t[i];
        if(i!=0){
            ll a1=1;
            ll t1=1;
            if(a[i]<a[i-1]){
                a1=a[i-1]/a[i];
                if(a[i-1]%a[i]!=0)++a1;
            }
            if(t[i]<t[i-1]){
                t1=t[i-1]/t[i];
                if(t[i-1]%t[i]!=0)++t1;
            }
            a[i]*=max(a1,t1);
            t[i]*=max(a1,t1);                
            }
    }
    cout<<a[n-1]+t[n-1]<<endl;
	return 0;
}