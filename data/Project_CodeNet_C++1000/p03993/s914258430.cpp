#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using ll=long long;
using namespace std;

template<class T>
T lcm(T a,T b){
    return a/__gcd(a,b)*b;
}

int main(){
    int n;cin >> n;
    long ans=0;
    vector<long> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i]--;
    }
    for(int i=0;i<n;i++){
        if(a[a[i]]==i){
            ans++;
        }
    }
    cout << ans/2;
    return 0;
}