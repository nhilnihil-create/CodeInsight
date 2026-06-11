#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
using tpl = tuple<int, int, int>;
typedef pair<int,int> pii;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

ll X, Y;

int dp[101][101];
int dfs(int x, int y){
    if(dp[x][y]>=0) return dp[x][y];
    int res = 0;
    if(x <= 1 && y <= 1) {
        res = 0;
    }
    else{
        for(int i = 1; 0 <= x - i * 2; i++){
            res |= !dfs(x - i * 2, i + y);
        }
        for(int i = 1; 0 <= y - i * 2; i++){
            res |= !dfs(x + i, y - i * 2);
        }
    }
    return dp[x][y] = res;
}

int main(){

    cin >> X >> Y;
    // memset(dp, -1, sizeof(dp));
    // for(int x = 0; x <= 13; x++){
    //     for(int y = 0; y<= 13; y++){
    //         cout << x << ", " << y << ", " << dfs(x, y) << endl;
    //     }
    // }

    ll max_v = max(X, Y);
    ll min_v = min(X, Y);
    if(max_v - min_v >= 2){
        cout << "Alice" << endl;
    }
    else{
        cout << "Brown" << endl;
    }


    return 0;
}
