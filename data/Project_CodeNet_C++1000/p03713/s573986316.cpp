#include<iostream>
#include<cstdio>

#include<vector>
#include<string>

#include<algorithm>
#include<cmath>

#include<deque>

using namespace std;
typedef long long ll;
const ll INF = 1e12+1;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}

ll H, W;

int main() {
    cin >> H >> W;
    if (H % 3 == 0 || W % 3 == 0) {
        cout << 0 << endl;
        return 0;
    } 
//4 4   664->2
//5 5   88

//短い辺と並行に分断したほうが明らかに誤差は少なくなる

    ll res = INF;
    
    for (int h = 1; h <= H-1; h++) {
        ll A = h * W;
        ll B = ((H-h) / 2) * W;
        ll C = H*W - A - B;
        chmin(res, max(A,max(B,C))-min(A,min(B,C)));
        B = (W / 2) * (H-h);
        C = H*W - A - B;
        chmin(res, max(A,max(B,C))-min(A,min(B,C)));
    }
    swap(H,W);
    for (int h = 1; h <= H-1; h++) {
        ll A = h * W;
        ll B = ((H-h) / 2) * W;
        ll C = H*W - A - B;
        chmin(res, max(A,max(B,C))-min(A,min(B,C)));
        B = (W / 2) * (H-h);
        C = H*W - A - B;
        chmin(res, max(A,max(B,C))-min(A,min(B,C)));
    }
    cout << res << endl;
}