#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;

int main() {
    long long H,W;
    int N;
    cin >> H >> W >> N;
    map<pp, int> square; 
    for(int i=0; i<N; ++i) {
        int a,b;
        cin >> a >> b;
        --a; --b;
        for(int j=0; j<3; ++j) {
            for(int k=0; k<3; ++k) {
                int p = a - j;
                int q = b - k;
                if(p >= 0 && p + 2 < H && q >= 0 && q + 2 < W) {
                    square[pp(p,q)] += 1;
                }
            }
        }
    }

    cout << (H - 2) * (W - 2) - square.size() << endl;
    for(int i=1; i<=9; ++i) {
        int cnt = 0;
        for(auto itr = square.begin(); itr != square.end(); ++itr) {
            if(itr->second == i) ++cnt;
        }
        cout << cnt << endl;
    }
    return 0;
}