#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
signed main() {
    int H,W;
    cin >> H >> W;
    int ans = INF;
    for(int i = 1; i < H; i++) {
        int cnt = i*W;
        int X = (H-i)/2*W;
        int Y = ((H-i)-(H-i)/2)*W;
        int A = (H-i)*(W/2);
        int B = (H-i)*(W-W/2);
        ans = min(ans,max(max(cnt,X),Y)-min(min(cnt,X),Y));
        ans = min(ans,max(max(cnt,A),B)-min(min(cnt,A),B));
    }
    for(int i = 1; i < W; i++) {
        int cnt = i*H;
        int X = (W-i)/2*H;
        int Y = ((W-i)-(W-i)/2)*H;
        int A = (W-i)*(H/2);
        int B = (W-i)*(H-H/2);
        ans = min(ans,max(max(cnt,X),Y)-min(min(cnt,X),Y));
        ans = min(ans,max(max(cnt,A),B)-min(min(cnt,A),B));
    }
    cout << ans << endl;
}