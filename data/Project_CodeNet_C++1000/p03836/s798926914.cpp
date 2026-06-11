#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,N) for(int i = 0; i < (N); i++)

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

const long long INF = 1LL << 60;

//入力
int sx,sy,tx,ty;


int main(){
    cin >> sy >> sx >> ty >> tx;
    for (int i = 0; i < (tx - sx); i++){
        cout << 'U';
    }
    for (int i = 0; i < (ty - sy); i++){
        cout << 'R';
    }
    for (int i = 0; i < (tx - sx); i++){
        cout << 'D';
    }
    for (int i = 0; i < (ty - sy); i++){
        cout << 'L';
    }
    cout << 'L';
    for (int i = 0; i < (tx - sx + 1); i++){
        cout << 'U';
    }
    for (int i = 0; i < (ty - sy + 1); i++){
        cout << 'R';
    }
    cout << 'D';
    cout << 'R';
    for (int i = 0; i < (tx - sx + 1); i++){
        cout << 'D';
    }
    for (int i = 0; i < (ty - sy + 1); i++){
        cout << 'L';
    }
    cout << 'U' << endl;
}
