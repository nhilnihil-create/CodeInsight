#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<ll,ll>;
using grid = vector<vector<int>>;

const int dx[2] = {1, 0};
const int dy[2] = {0, 1};
const int INF = 1<<30;
const ll mod = 998244353LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N,M;
    cin>>N>>M;
    vector<vector<int>> v(M,vector<int>(2));
    map<int,int> m;
    rep(i,N) {
        int x;
        cin>>x;
        m[x]++;
    }
    for(auto x:m){
        v[(x.first)%M][0] += x.second;
        v[(x.first)%M][1] += x.second%2;
    }
    int ans = 0;
    if(M%2==0){
        ans += v[0][0]/2;
        for(int i = 1; i < M/2;i++){
            if(v[i][0]>v[M-i][0]){
                if(v[i][1]>v[M-i][0]){
                    ans += v[M-i][0] + (v[i][0]-v[i][1]) / 2;
                }
                else ans += (v[i][0]+v[M-i][0])/2;
            }
            if(v[i][0]==v[M-i][0]) ans += (v[i][0]+v[M-i][0])/2;
            if(v[i][0]<v[M-i][0]) {
                if(v[i][0]<v[M-i][1]) {
                    ans += v[i][0] + (v[M-i][0]-v[M-i][1]) / 2;
                }
                else ans += (v[i][0]+v[M-i][0])/2;
            }
        }
        ans += v[M/2][0]/2;
    }
    else {
        ans += v[0][0]/2;
        for(int i = 1; i <= M/2;i++){
            if(v[i][0]>v[M-i][0]){
                if(v[i][1]>v[M-i][0]){
                    ans += v[M-i][0] + (v[i][0]-v[i][1]) / 2;
                }
                else ans += (v[i][0]+v[M-i][0])/2;
            }
            if(v[i][0]==v[M-i][0]) ans += (v[i][0]+v[M-i][0])/2;
            if(v[i][0]<v[M-i][0]) {
                if(v[i][0]<v[M-i][1]) {
                    ans += v[i][0] + (v[M-i][0]-v[M-i][1]) / 2;
                }
                else ans += (v[i][0]+v[M-i][0])/2;
            }
        }
    }
    cout<<ans<<endl;
}