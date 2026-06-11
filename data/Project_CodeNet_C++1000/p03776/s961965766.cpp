#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;

//パスカルの三角形を使用してCOMを求める
//MODしないバージョン
ll COM[51][51];

void COMinit(int n){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(j == 0 || j == i) COM[i][j] = 1;
            else COM[i][j] = (COM[i-1][j-1] + COM[i-1][j]);
        }
    }
}


int main(){
    COMinit(50);

    int n, a, b;
    cin >> n >> a >> b;
    vector<double> v(n);
    rep(i, n) cin >> v[i];
    sort(rall(v));

    double maxv = 0;
    rep(i, a) maxv += v[i];
    maxv /= a;

    cout << fixed << setprecision(9) << maxv << endl;

    ll ans = 0;
    double va = v[a-1];
    
    if(v[0] != va){
        int y = 0, x = 0, idx = 0;
        while(idx < n){
            if(idx < a && va == v[idx]) x++;
            if(va == v[idx]) y++;
            idx++;
        }
        ans += COM[y][x];
    }
    else if(v[0] == va){
        int y = 0;
        rep(i, n) y += (va == v[i]);
        for(int x = a; x <= min(y, b); x++) ans += COM[y][x];
    }

    cout << ans << endl;
}