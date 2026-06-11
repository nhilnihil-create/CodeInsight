#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main(){
    int x,y;
    cin >> x >> y;
    int ans = INF;
    if(x <= y) {
        ans = min(ans,y-x);
    }
    if(-x <= y) {
        ans = min(ans,y+x+1);
    }
    if(x <= -y) {
        ans = min(ans,-y-x+1);
    }
    if(-x <= -y) {
        ans = min(ans,-y+x+2);
    }
    cout << ans << endl;
}
