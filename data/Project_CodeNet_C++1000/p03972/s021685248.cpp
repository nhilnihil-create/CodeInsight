#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long H, W; cin >> W >> H;
    vector<long long> p(W);
    vector<long long> q(H);
    priority_queue<long long, vector<long long>, greater<long long>> p_pq;
    priority_queue<long long, vector<long long>, greater<long long>> q_pq;
    for (int i = 0; i < W; i++) {
        cin >> p[i];
        p_pq.push(p[i]);
    }
    for (int i = 0; i < H; i++) {
        cin >> q[i];
        q_pq.push(q[i]);
    }
    p_pq.push(100000000000);
    q_pq.push(100000000000);
    
    long long p_cnt = 0;
    long long q_cnt = 0;
    long long ans = 0;
    for (int i = 0; i < H+W; i++) {
        long long p_top = p_pq.top();
        long long q_top = q_pq.top();
        if (p_top < q_top) {
            ans += p_top * (H - q_cnt + 1);
            p_cnt++;
            p_pq.pop();
        } else {
            ans += q_top * (W - p_cnt + 1);
            q_cnt++;
            q_pq.pop();
        }
    }
    cout << ans << endl;
}
