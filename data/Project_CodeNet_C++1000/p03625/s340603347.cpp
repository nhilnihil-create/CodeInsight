#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N; cin >> N;
    map<int,int> MAP;
    rep(i,N) {
        int a; cin >> a;
        MAP[a]++;
    }
    ll ma = 0;
    ll ma2 = 0;
    map<int,int>::reverse_iterator p = MAP.rbegin();
    for (;p != MAP.rend(); p++) {
        if (p->second >= 4) {
            if (ma == 0) {
                ma = p->first;
                ma2 = p->first;
                break;
            } else {
                ma2 = p->first;
                break;
            }
        } else if (p->second >= 2) {
            if (ma == 0) ma = p->first;
            else {
                ma2 = p->first;
                break;
            }
        }
    }
    
    cout << ma * ma2 << endl;
}
