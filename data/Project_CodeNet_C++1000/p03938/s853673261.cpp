#include <bits/stdc++.h>
#define M 40000
typedef long long ll;
using namespace std;

int main(){
    ll n; cin>>n;
    vector<ll> p(n);
    vector<ll> a(n);
    vector<ll> b(n);

    for(int i=0; i<n; i++){
        cin>>p[i]; p[i]--;
    }

    for(int i=0; i<n; i++){
        a[i] = i*M+1;
    }

    for(int i=0; i<n; i++){
        b[i] = (n-i)*M+1;
    }

    for(int i=0; i<n; i++){
        a[p[i]] += i;
    }

    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

     for(int i=0; i<n; i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;

    return 0;
}