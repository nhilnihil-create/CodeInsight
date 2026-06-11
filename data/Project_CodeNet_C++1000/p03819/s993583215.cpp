#include<bits/stdc++.h>
#define taskname "A"
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int maxn = 3e5 + 5;

int n , m;
vector<int> adj[maxn];
int res[maxn];
int bit[maxn];

void update(int x,int y){
    for( ; x <= m ; x += x & -x){
        bit[x] += y;
    }
}

int query(int x){
    int res = 0;
    for( ; x > 0 ; x &= x - 1){
        res += bit[x];
    }
    return res;
}

int main(){
    if(fopen(taskname".INP","r")){
        freopen(taskname".INP","r",stdin);
        freopen(taskname".OUT","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i){
        int l , r;cin >> l >> r;
        adj[r - l + 1].pb(l);
    }
    for(int i = m ; i >= 1 ; --i){
        res[i] = res[i + 1] + adj[i + 1].size();
    }
    for(int i = 1 ; i <= m ; ++i){
        for(int c : adj[i]){
            update(c , 1);
            update(c + i , -1);
        }
        for(int j = i ; j <= m ; j += i){
            res[i] += query(j);
        }
        cout << res[i] << '\n';
    }
}

