#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define vv(T) vector<vector<T>>
#define coa cout << ans << endl
using namespace std;
using ll = long long;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vbool = vector<bool>;
using vvbool = vector<vector<bool>>;
using qint = queue<int>;
using sint = stack<int>;
using pii = pair<int, int>;

void op(vector<pair<bool, int>> &balls, int x, int y){
    balls[x].second--;
    balls[y].second++;
    if(balls[x].first){
        balls[y].first = true;
    }
    if(balls[x].second == 0){
        balls[x].first = false;
    }
    return;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<pair<bool, int>> balls(n, make_pair(0, 1));  //red, num
    balls[0] = make_pair(1, 1);

    rep(i, m){
        int x, y;
        cin >> x >> y;
        x--; y--;
        op(balls, x, y);
    }

    int ans = 0;
    rep(i, n){
        if(balls[i].first) ans++;
    }

    cout << ans << endl;
    return 0;
}
