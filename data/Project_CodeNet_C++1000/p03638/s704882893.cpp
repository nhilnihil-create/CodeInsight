#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> P;

signed main(){
    int H, W; cin >> H >> W;
    int N; cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    vector<vector<int> > color(H + 1, vector<int> (W + 1));
    P p = P(1, 1);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < a[i]; j++){
            color[p.first][p.second] = i + 1;
            if(p.first %2 == 1 && p.second != W) p.second++;
            else if(p.first %2 == 1 && p.second == W) p.first++;
            else if(p.first %2 == 0 && p.second != 1) p.second--;
            else if(p.first %2 == 0 && p.second == 1) p.first++;
        }
    }
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cout << color[i][j] << " ";
        }
        cout << endl;
    }
}