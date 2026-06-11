#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

using namespace std;

vector<ll> a,b;
set<pair<ll,ll>>st;
set<pair<ll,ll>>used;
ll H,W,N;

int f(int x,int y){
    // 左上がx,yの3*3の正方形の中に含まれる黒い点のかずをかえす
    if(used.count({x,y}))return 0;
    used.insert({x,y});

    int ret = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(st.count({x+i,y+j}))ret++;
        }
    }
    return ret;
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    cin >> H >> W >> N;
    
    a.resize(N);
    b.resize(N);
    rep(i,N){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
        st.insert({a[i],b[i]});
    }
    vector<ll> cnt(10,0); // cnt[i] := 3*3の中に黒い点がi個ある正方形の個数
    rep(i,N){
        // ある点(a[i],b[i])について、{a[i],b[i]}を含むような正方形は左上の座標が
        // a[i]-2,b[i]-2 から始まって a[i],b[i]にくるんで
        int sx = a[i] - 2;
        int sy = b[i] - 2;
        for(int x = 0 ; x < 3 ; x ++ ){
            for(int y = 0 ; y < 3 ; y ++ ){
                int nx  = sx + x;
                int ny  = sy + y;
                if( nx < 0 || ny < 0 || nx + 2 >= H || ny + 2 >= W) continue;
                cnt[f(nx,ny)] ++ ;
            }
        }
    }
    ll ans = (H-2)*(W-2);
    rep(i,9)ans -= cnt[i+1];
    cnt[0] = ans;
    rep(i,10)cout << cnt[i] << endl;
}