#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1000000000;

int main() {
    int H, W;
    cin >> H >> W;
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWZXYZ";
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            string s;
            cin >> s;
            if (s == "snuke"){
                cout <<abc[j] << i+1 << endl;
                exit(0);
            }
        }
    }
}