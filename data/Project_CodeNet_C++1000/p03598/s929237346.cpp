#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int N,K;
    cin >> N >> K;
    vector<int> x(N);
    rep(i,N) cin >> x.at(i);
    int ans=0;
    rep(i,N){
        ans+=2*min(abs(x.at(i)),abs(K-x.at(i)));
    }
    cout << ans << endl;
}