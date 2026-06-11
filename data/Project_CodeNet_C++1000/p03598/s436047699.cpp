#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int N,K;
    cin>>N>>K;
    int ans=0;
    vector<int>X(N);
    rep(i,N){
        cin>>X[i];
        ans+=min(X[i],K-X[i])*2;
    }
    cout<<ans<<endl;
}
