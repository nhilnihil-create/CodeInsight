#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;

typedef unsigned long long ll;

const long long MOD = 1000000000 + 7;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    int h,w;
    cin >> h >> w;
    string line;
    vector<vector<char>> rslt;
    rep(i,h){
        cin >> line;
        vector<char> input;
        rep(j,w){
            input.push_back(line[j]);
        }
        rslt.push_back(input);
        rslt.push_back(input);
    }
    
    rep(i,2*h){
        rep(j,w){
            cout << rslt[i][j];
        }
        cout << endl;
    }
    return 0;
}
