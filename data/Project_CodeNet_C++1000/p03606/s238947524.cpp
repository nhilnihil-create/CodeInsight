#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int N;
    cin>>N;
    vector<int>A(N);
    vector<int>B(N);
    ll ans=0;
    rep(i,N){
        cin>>A[i];
        cin>>B[i];
        ans+=B[i]-A[i]+1;
    }
    cout<<ans<<endl;
}

