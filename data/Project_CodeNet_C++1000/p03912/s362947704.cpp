#include<bits/stdc++.h>
using namespace std;

int main(void) {
    long n, m;
    cin >> n >> m;

    map<long,long> cnt;
    for(long i=0; i<n; i++) {
        long x;
        cin >> x;
        cnt[x]++;
    }

    vector<queue<long>> vq(m);
    for(auto &t: cnt) {
        long x, c;
        tie(x, c) = t;
        if(c&1) vq[x%m].push(x);
    }

    for(auto &t: cnt) {
        long x, c;
        tie(x, c) = t;
        for(long i=0; i<c/2; i++)
            vq[x%m].push(x), vq[x%m].push(x);
    }

    long r = 0;
    for(long i=1; 2*i<m; i++) {
        while(!vq[i].empty() && !vq[m-i].empty()) {
            auto x = vq[i].front(); vq[i].pop();
            auto y = vq[m-i].front(); vq[m-i].pop();
            cnt[x]--, cnt[y]--;
            r++;
        }
    }
    if(~m&1) {
        long i = m/2;
        while(vq[i].size() >= 2) {
            auto x = vq[i].front(); vq[i].pop();
            auto y = vq[m-i].front(); vq[m-i].pop();
            cnt[x]--, cnt[y]--;
            r++;
        }
    }
    {
        long i = 0;
        while(vq[i].size() >= 2) {
            auto x = vq[i].front(); vq[i].pop();
            auto y = vq[i].front(); vq[i].pop();
            cnt[x]--, cnt[y]--;
            r++;
        }
    }

    for(auto t: cnt) {
        long x, c;
        tie(x, c) = t;
        r += c/2;
    }

    cout << r << endl;
}
