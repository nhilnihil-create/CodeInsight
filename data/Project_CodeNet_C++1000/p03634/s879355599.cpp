#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

void bfs(queue<ll> que, vector<ll> &isVisited, vector<vector<ll> > &vec, ll K, vector<vector<pair<ll,ll> > > &length){
    que.push(K);
    isVisited[K] = 0;
    while(que.size() != 0){
        int q = que.front();
        rep(i,vec[q].size()){
            if (isVisited[vec[q][i]] == -1){
                que.push(vec[q][i]);
                isVisited[vec[q][i]] = isVisited[q] + length[q][i].second;
            }
        }
        que.pop();
    }
}

int main(){
    ll N;
    cin >> N;
    vector<ll> a(N - 1);
    vector<ll> b(N - 1);
    vector<ll> c(N - 1);
    rep(i,N - 1){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
    }
    ll Q,K;
    cin >> Q >> K;
    K--;
    vector<ll> x(Q);
    vector<ll> y(Q);
    rep(i,Q){
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }
    vector<vector<ll> > connection(N, vector<ll> (0));
    rep(i,N - 1){
        connection[a[i]].push_back(b[i]);
        connection[b[i]].push_back(a[i]);
    }
    vector<ll> isVisited(N, -1);
    vector<vector<pair<ll,ll> > > length(N, vector<pair<ll,ll> > (0));
    rep(i,N - 1){
        length[a[i]].push_back(pair<ll,ll> (b[i], c[i]));
        length[b[i]].push_back(pair<ll,ll> (a[i], c[i]));
    }
    queue<ll> que;
    bfs(que, isVisited, connection, K, length);
    rep(i,Q){
        cout << isVisited[x[i]] + isVisited[y[i]] << endl;
    }
}
