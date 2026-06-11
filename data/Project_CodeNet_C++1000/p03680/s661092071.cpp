#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (int i = int(x); i < (int)(n); i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
using ll = long long;

int main() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    vector<bool> history(n);
    rep(i, n) {
        cin >> a[i];
        history[i] = false;
    }

    ll curpt = 1;
    ll cnt = 0;

    // vector<ll> history;
    // history.push_back(curpt);
    bool isDone = false;

    while (isDone == false) {
        cnt++;
        curpt = a[curpt - 1];

        if (curpt == 2) {
            isDone = true;
        } else {
            if(history[curpt - 1]){
                isDone = true;
                cnt = -1;
            }
        }

        history[curpt - 1] = true;
    }

    cout << cnt << endl;
}