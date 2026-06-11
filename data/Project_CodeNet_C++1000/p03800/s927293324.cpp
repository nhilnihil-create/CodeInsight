#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll ZERO = 0;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int N;
string S;

string k(int a,int b) {
    vector<int> ret(N + 2);
    ret.at(0) = a;
    ret.at(1) = b;
    for(int i = 1;i < N + 1;i++) {
        if(ret.at(i) == 1) {
            if(S.at(i - 1) == 'o') {
                ret.at(i + 1) = ret.at(i - 1);
            }
            else {
                if(ret.at(i - 1) == 1) {
                    ret.at(i + 1) = 2;
                }
                else if(ret.at(i - 1) == 2) {
                    ret.at(i + 1) = 1;
                }
            }
        }
        else {
            if(S.at(i - 1) == 'x') {
                ret.at(i + 1) = ret.at(i - 1);
            }
            else {
                if(ret.at(i - 1) == 1) {
                    ret.at(i + 1) = 2;
                }
                else if(ret.at(i - 1) == 2) {
                    ret.at(i + 1) = 1;
                }
            }
        }
    }
    if(ret.at(0) != ret.at(N) || ret.at(1) != ret.at(N + 1)) {
        return "-1";
    }
    else {
        string ret2;
        for(int i = 1;i < N + 1;i++) {
            if(ret.at(i) == 1) {
                ret2 += 'S';
            }
            else {
                ret2 += 'W';
            }
        }
        return ret2;
    }
}

int main() {
    cin >> N;
    cin >> S;
    if(k(1,1) != "-1") {
        cout << k(1,1) << endl;
    }
    else if(k(1,2) != "-1") {
        cout << k(1,2) << endl;
    }
    else if(k(2,1) != "-1") {
        cout << k(2,1) << endl;
    }
    else if(k(2,2) != "-1") {
        cout << k(2,2) << endl;
    }
    else {
        cout << -1 << endl;
    }
}