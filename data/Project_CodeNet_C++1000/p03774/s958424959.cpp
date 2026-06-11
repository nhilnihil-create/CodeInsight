#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1000000000;
typedef pair<int,int> P;

int main() {
    int N, M;
    cin >> N >> M;
    vector<P>students(N);
    vector<P>checkpoints(M);
    for (int i=0; i<N; i++) cin >> students[i].first >> students[i].second;
    for (int i=0; i<M; i++)cin >> checkpoints[i].first >> checkpoints[i].second;

    for (int i=0; i<N; i++){
        int ans = 0;
        int last_dis = INF;
        int sx, sy;
        sx = students[i].first;
        sy = students[i].second;

        for (int j=0; j<M; j++){
            int dis;
            dis = abs(checkpoints[j].first - sx) +  abs(checkpoints[j].second - sy);
            if (dis < last_dis){
                last_dis = dis;
                ans = j;
            }
        }

        cout << ans+1 << endl;
    }
}