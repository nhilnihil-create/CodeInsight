#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
//const int MODINF = 1000000007;
using namespace std;

int main(){
    int64_t H, W;
    cin >> H >> W;
    int64_t S_fin = H * W;
    rep(i, 0, 2){
        rep(w, 0, W + 1){
            int64_t S_1 = H * w;
            int64_t S_2 = (H/2) * (W - w);
            int64_t S_2_2 = ((H + 1)/2)*(W - w);
            int64_t S_3 = ((W - w)/2) * H;
            int64_t S_3_2 = ((W - w + 1) / 2) * H;
            int64_t S_dif_1 = max(abs(S_1 - S_2), abs(S_1 - S_2_2));
            int64_t S_dif_2 = max(abs(S_1 - S_3), abs(S_1 - S_3_2));
            int64_t S_dif = min(S_dif_1, S_dif_2);
            //cout << "w " << w << " S " << S_dif << endl;
            S_fin = min(S_fin, S_dif);
        }
        swap(W, H);
    }
    cout << S_fin << endl;
}