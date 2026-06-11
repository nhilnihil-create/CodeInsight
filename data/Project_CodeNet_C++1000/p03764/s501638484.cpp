#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    long long mod=1e9+7;
    long n,m;
    cin>>n>>m;
    vector<long long> x;
    vector<long long> y;
    for(long i=0;i<n;i++){
        long long k;
        cin>>k;
        x.push_back(k);
    }
    for(long i=0;i<m;i++){
        long long k;
        cin>>k;
        y.push_back(k);
    }
    vector<long long> v1;
    vector<long long> v2;
    for(long i=1;i<n;i++){
        v1.push_back(x[i]-x[i-1]);
    }
    for(long i=1;i<m;i++){
        v2.push_back(y[i]-y[i-1]);
    }
    long long ansx=0;
    for(long i=0;i<n-1;i++){
        long long k=v1[i]*(i+1)*(n-i-1);
        ansx+=k;
        ansx=ansx%mod;
    }
    long long ansy=0;
    for(long i=0;i<m-1;i++){
        long long k=v2[i]*(i+1)*(m-i-1);
        ansy+=k;
        ansy=ansy%mod;
    }
    long long k=ansx*ansy;
    k=k%mod;
    cout<<k;
    return 0;
}
