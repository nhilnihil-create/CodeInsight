#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;

template<typename T> bool chmin(T &a,const T b){if(a>b){a=b; return true;}return false;}
template<typename T> bool chmax(T &a,const T b){if(a<b){a=b; return true;}return false;}



int main(){
    int N, M, R; cin >> N >> M >> R;
    vi r(R);
    for(auto &x : r){
        cin >> x;
        x--;
    }
    vii dist(N, vi(N, INF));
    for(int i=0; i<N; i++) dist[i][i]=0;
    for(int i=0; i<M; i++){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        dist[a][b]=c;
        dist[b][a]=c;
    }
    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                chmin(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    vi ord(R);
    ll ans=LINF;
    for(int i=0; i<R; i++) ord[i]=r[i];
    sort(all(ord));
    do{
        ll sum=0;
        for(int i=0; i<R-1; i++){
            sum+=dist[ord[i]][ord[i+1]];
        }
        chmin(ans, sum);
    }while(next_permutation(all(ord)));

    cout << ans << endl;
    return 0;
}