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
    int ai, bi, ci;
    ai = bi = ci = 0;
    string sa, sb, sc;
    cin >> sa;
    cin >> sb;
    cin >> sc;
    int now = 0;

    while (true){
        if (now == 0){
            if (ai > sa.size()-1){
                cout << "A" << endl;
                exit(0);
            }
            char ci = sa[ai];
            if (ci == 'a')now = 0;
            else if (ci == 'b')now = 1;
            else now = 2;
            ai++;
            continue;
        }
        if (now == 1){
            if (bi > sb.size()-1){
                cout << "B" << endl;
                exit(0);
            }
            char ci = sb[bi];
            if (ci == 'a')now = 0;
            else if (ci == 'b')now = 1;
            else now = 2;
            bi++;
            continue;
        }
        else {
            if (ci > sc.size()-1){
                cout << "C" << endl;
                exit(0);
            }
            char ch = sc[ci];
            if (ch == 'a')now = 0;
            else if (ch == 'b')now = 1;
            else now = 2;
            ci++;
            continue;
        }
    }
}