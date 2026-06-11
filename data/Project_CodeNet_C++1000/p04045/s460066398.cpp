#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>inline bool chmax(T &a, T b){if (a < b){a = b;return true;}return false;}
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Pl = pair<long long, long long>;
using veci = vector<int>;
using vecl = vector<long long>;
using vecveci = vector<vector<int>>;
using vecvecl = vector<vector<long long>>;

int main() {
    int N,K;
    cin >> N >> K;
    queue<int> que;
    veci D(10,1);
    REP(i,K) {
        int d; cin >> d;
        D[d] = 0;
    }
    for(int i = 1; i < 10; i++) if(D[i]) que.push(i);
    while(1) {
        int v = que.front();
        que.pop();
        //cout << v << endl;
        if(v >= N) {
            cout << v << endl;
            return 0;
        }
        REP(i,10) if(D[i]) que.push(v*10+i);
    }
}
