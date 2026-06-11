#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int h, w;
    cin >> h >> w;

    int n;
    cin >> n;

    vector<int> a(n);
    for(int in=0;in<n;in++) {
        cin >> a.at(in);
    }

    vector<int> c(h*w);
    int cnt = 0;
    for(int in=0;in<n;in++) {
        for(int jn=0;jn<a.at(in);jn++) {
            c.at(cnt) = in + 1;
            cnt++;
        }
    }

    bool forrev = true;
    int diff = w-1;
    for(int ihw=0;ihw<h*w;ihw++) {
        if(forrev==true) {
            cout << c.at(ihw) << " ";
        }
        else {
            cout << c.at(diff-ihw) << " ";
        }
        if(ihw%w==w-1) { 
            cout << endl;
            forrev = !forrev;
            diff += 2*w;
        }
    }
    return 0;
}
