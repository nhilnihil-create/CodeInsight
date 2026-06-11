#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, f, n) for (int i = (f); i < (n); i++)
ll const INF = 1LL << 60;

int main() {
    int W, H, N;
    cin >> W >> H >> N;

    int X[N];
    int Y[N];
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> A[i];
    }

    int visit[W][H];
    for (int x = 0; x < W; x++) {
        for (int y = 0; y < H; y++) {
            visit[x][y] = 0;
        }
    }
    

    for (int i = 0; i < N; i++) {
        if (A[i] == 1) {
            for (int x = 0; x < X[i]; x++) {
                for (int y = 0; y < H; y++) {
                    visit[x][y] = 1;
                }
            }
        } else if (A[i] == 2) {
            for (int x = X[i]; x < W; x++) {
                for (int y = 0; y < H; y++) {
                    visit[x][y] = 1;
                }
            }
        } else if (A[i] == 3) {
            for (int x = 0; x < W; x++) {
                for (int y = 0; y < Y[i]; y++) {
                    visit[x][y] = 1;
                }
            }
        } else if (A[i] == 4) {
            for (int x = 0; x < W; x++) {
                for (int y = Y[i]; y < H; y++) {
                    visit[x][y] = 1;
                }
            }
        }
    }

    int ans = 0;
    for (int y = H-1; y >=0; y--) {
        for (int x = 0; x < W; x++) {
            if (visit[x][y] == 0)
                ans++;
            // cout << visit[x][y] << " ";
        }
        // cout << endl;
    }

    cout << ans << endl;


   return 0;
}