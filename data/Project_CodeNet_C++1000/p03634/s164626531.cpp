#include"bits/stdc++.h"
#include<unordered_set>
#include<unordered_map>
#include<random>
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9+7);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(int)(n); (i)++)
int dx[4]={ 1,0,-1,0 };
int dy[4]={ 0,1,0,-1 };

int N, Q, K;
vector<pair<int, int>> e[100000];

ll dep[100000];
void depth(int n, int p, ll d){
    dep[n] = d;
    rep(i, e[n].size()){
        if(e[n][i].first == p) continue;
        depth(e[n][i].first, n, d+e[n][i].second);
    }
}

signed main(){
    cin >> N;
    rep(i, N-1){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        e[a].pb({ b, c });
        e[b].pb({ a, c });
    }
    cin >> Q >> K;
    depth(K-1, -1, 0);
    rep(i, Q){
        int a, b;
        cin >> a >> b;
        cout << dep[a-1] + dep[b-1] << endl;
    }
}