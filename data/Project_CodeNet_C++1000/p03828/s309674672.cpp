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

int main(){
    int N;
    cin>>N;
    map<int,int> m;
    for(int i = 2; i <= N; i++){
        int t = i;
        for(int j = 2; j*j<=i; j++){
            while(t%j==0){
                t/=j;
                m[j]++;
            }
        }
        if(t!=1) m[t]++;
    }
    ll ans = 1;
    for(auto x:m){
        ans = (ans * (x.second+1))%mod;
    }
    cout<<ans<<endl;
} 