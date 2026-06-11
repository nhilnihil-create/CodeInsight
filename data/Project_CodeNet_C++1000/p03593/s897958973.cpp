#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll ZERO = 0;
const int Inf = 1000000000;
const ll INF= 1e18;
const ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int main() {
    int H,W;
    cin >> H >> W;
    vector<int> vec(26);
    for(int i = 0;i < H;i++) {
        for(int j = 0;j < W;j++) {
            char A;
            cin >> A;
            vec.at(A - 'a')++;
        }
    }
    int four = 0;
    int two = 0;
    int one = 0;
    for(int i = 0;i < 26;i++) {
        if(vec.at(i) != 0) {
            if(vec.at(i) % 4 == 0) {
                four++;
            }
            else if(vec.at(i) % 2 == 0) {
                two++;
            }
            else {
                one++;
                if((vec.at(i) - 1) % 4 == 0) {
                    four++;
                }
                else {
                    two++;
                }
            }
        }
    }
    if(H % 2 == 0 && W % 2 == 0) {
        if(two != 0 || one != 0) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }
    }
    else if(H % 2 == 0) {
        if(two >= H / 2 + 1 || one != 0) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }
    }
    else if(W % 2 == 0) {
        if(two >= W / 2 + 1 || one != 0) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }
    }
    else {
        if(two >= H / 2 + W / 2 + 1 || one != 1) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }
    }
}