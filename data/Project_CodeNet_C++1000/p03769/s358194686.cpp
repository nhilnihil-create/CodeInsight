#include "bits/stdc++.h"
using namespace std;

#define all(x)  x.begin(), x.end()
#define mp      make_pair
#define pii     pair<int, int>
#define ll      long long

void solve() {
        long long n;
        cin >> n;
        vector<int> pf;
        for (int i = 1; i <= 80; i ++) pf.push_back(i);
        deque<int> ps;
        long long now = n + 1;
        vector<bool> front;
        while (now > 1) {
                if (now & 1) front.push_back(true);
                front.push_back(false);
                now /= 2;
        }
        reverse(all(front));
        //for (int i = 0; i < front.size(); i ++) cout << front[i] << ' ';
        //cout << endl;
        int k = 1;
        for (int i = 0; i < front.size(); i ++) {
                if (front[i]) ps.push_front(k ++);
                else ps.push_back(k ++);
        }
        cout << pf.size() + ps.size() << endl;
        for (int i = 0; i < pf.size(); i ++) cout << pf[i] << ' ';
        for (int i = 0; i < ps.size(); i ++) cout << ps[i] << (i == ps.size() - 1 ? '\n' : ' ');
        return;
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);

        //int T;
        //freopen("a.in", "r", stdin);
        //cin >> T;
        //while (T --) solve();
        
        solve();
        return 0;
}

