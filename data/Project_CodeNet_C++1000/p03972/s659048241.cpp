#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int W, H;
vector<int> P, Q;

int main() {
    scanf("%d %d", &W, &H);
    P.resize(W);
    for(int i = 0; i < W; i++) {
        scanf("%d", &P[i]);
    }
    Q.resize(H);
    for(int i = 0; i < H; i++) {
        scanf("%d", &Q[i]);
    }

    int rcnt = 0, ccnt = 0;
    int pos1 = 0, pos2 = 0;

    sort(P.begin(), P.end());
    sort(Q.begin(), Q.end());

    ll cost = 0;
    while(pos1 < W && pos2 < H) {
        if(P[pos1] <= Q[pos2]) {
            cost += 1LL * P[pos1] * (H + 1 - ccnt);
            rcnt++;
            pos1++;
        }
        else {
            cost += 1LL * Q[pos2] * (W + 1 - rcnt);
            ccnt++;
            pos2++;
        }
    }
    while(pos1 < W) cost += 1LL * P[pos1] * (H + 1 - ccnt), rcnt++, pos1++;
    while(pos2 < H) cost += 1LL * Q[pos2] * (W + 1 - rcnt), ccnt++, pos2++;

    cout << cost;
}
