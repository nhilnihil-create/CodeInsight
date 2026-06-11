#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<int,int>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int K,T;
    cin>>K>>T;
    vector<int> a(T);
    rep(i,T) cin>>a[i];
    sort(a.begin(),a.end());
    if(K-a[T-1]>=a[T-1]-1) cout<<0<<endl;
    else cout<<a[T-1]-1-K+a[T-1]<<endl;
}