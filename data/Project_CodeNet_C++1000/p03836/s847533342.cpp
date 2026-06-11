#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INF INT_MAX // 2147483647
#define INFLL LLONG_MAX // 9223372036854775807
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define per(i, n) for(ll i=((ll)(n))-1; i>=0; i--)
#define perf(i, n) for(ll i=((ll)(n)); i>0; i--)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

vector<vector<bool>> color;

void coloring(ll sx, ll sy, string s){
    rep(i, s.size()-1){
        if(s[i] == 'U') sy++;
        else if(s[i] == 'D') sy--;
        else if(s[i] == 'R') sx++;
        else if(s[i] == 'L') sx--;
        color[sx][sy] = true;
    }
}

string bfs(ll sx, ll sy, ll tx, ll ty){
    // マスターをコピー
    vector<vector<bool>> tcolor(color.size(), vector<bool>(color[0].size(), false));
    rep(i, color.size()){ rep(j, color[i].size()) tcolor[i][j] = color[i][j]; }

    // キュー
    queue<pair<pair<ll, ll>, string>> que;
    que.push(make_pair(make_pair(sx, sy), ""));
    tcolor[sx][sy] = true;

    while(!que.empty()){
        auto front = que.front(); que.pop();
        ll x = front.first.first;   
        ll y = front.first.second;   
        string s = front.second;
        // 目的位置にたどり着いた場合
        if(x == tx && y == ty) return s;
        
        // それ以外の場合は移動できそうな場所をキューに積む（上下左右）
        if(y<tcolor[0].size()-1 && tcolor[x][y+1] == false) que.push(make_pair(make_pair(x, y+1), s+"U"));
        if(y>0 && tcolor[x][y-1] == false) que.push(make_pair(make_pair(x, y-1), s+"D"));
        if(x>0 && tcolor[x-1][y] == false) que.push(make_pair(make_pair(x-1, y), s+"L"));
        if(x<tcolor.size()-1 && tcolor[x+1][y] == false) que.push(make_pair(make_pair(x+1, y), s+"R"));
    }
}

int main(){
    Init();
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    string ans = "";

    // 差分
    ll dx = tx-sx;
    ll dy = ty-sy;

    // 内側時計回りで[s -> t -> s]を移動
    ans += string(dy, 'U') + string(dx, 'R');
    ans += string(dy, 'D') + string(dx, 'L');

    // 外側時計回りで[s -> t -> s]を移動
    ans += "L" + string(dy+1, 'U') + string(dx+1, 'R') + "D";
    ans += "R" + string(dy+1, 'D') + string(dx+1, 'L') + "U";

    cout << ans << endl;
}