#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    ll N;
    cin>>N;
    vector<ll>A(N);
    vector<ll>B(N);
    ll ma=-1000000000;
    rep(i,N){
        cin>>A[i];
        cin>>B[i];
        if(ma<A[i]){
            ma=A[i];
        }
    }
    rep(i,N){
        if(ma==A[i]){
            cout<<A[i]+B[i]<<endl;
        }
    }
}