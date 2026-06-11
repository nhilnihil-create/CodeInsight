#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}


int main() {
    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    for(int i = sx;i<tx;i++) {
        cout << "R";
    }
    for(int i = sy;i<ty;i++) {
        cout << "U";
    }
    for(int i = tx;i>sx;i--) {
        cout << "L";
    }
    for(int i = ty;i>sy;i--) {
        cout <<"D";
    }
    cout << "D";
    for(int i = sx;i<=tx;i++) {
        cout << "R";
    }
    for(int i = sy;i<=ty;i++) {
        cout << "U";
    }
    cout << "L";
    cout << "U";
    for(int i = tx;i>=sx;i--) {
        cout << "L";
    }
    for(int i = ty;i>=sy;i--) {
        cout <<"D";
    }
    cout << "R";
    cout << endl;
}