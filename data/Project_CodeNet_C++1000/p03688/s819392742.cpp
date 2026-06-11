#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<ll,ll>;
using graph = vector<vector<int>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N;
    cin>>N;
    int p=0,q =INF;
    vector<int> v(N);
    rep(i,N) {
        cin>>v[i];
        chmax(p,v[i]);
        chmin(q,v[i]);
    }
    bool can = true;
    if(p-q>1) can = false;
    else if(p==q){
        rep(i,N){
            if(v[i]!=N-1) can = false;
        }
        if(!can) {
            if(N>=p*2) can = true;
        }
    }
    else{
        int n = 0;
        rep(i,N) if(v[i]==q) n++;
        if(n>q||N-n<(p-n)*2) can = false;
    }
    if(can) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
