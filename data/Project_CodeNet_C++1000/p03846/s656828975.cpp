#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

llint pow2mod(llint n) {
    llint ans = 1;
    for(int in=0;in<n;in++) {
        ans *= 2;
        ans  %= MOD;
    }
    return ans;
}

int main(void) {
    llint n;
    cin >> n;

    vector<llint> a(n);
    llint atmp;
        for(int in=0;in<n;in++) {
            cin >> atmp;
            a.at(atmp)++;
        }
    if(n%2==0) {
        for(int in=0;in<n;in++) {
            if(in%2==1&&a.at(in)!=2) {
                cout << 0 << endl;
                return 0;
            }
            if(in%2==0&&a.at(in)!=0) {
                cout << 0 << endl;
                return 0;
            }
        }
        cout << pow2mod(n/2) << endl;
    }
    else {
        if(a.at(0)!=1) {
            cout << 0 << endl;
            return 0;
        }
        for(int in=0;in<n;in++) {
            if(in%2==1&&a.at(in)!=0) {
                cout << 0 << endl;
                return 0;
            }
            if(in!=0&&in%2==0&&a.at(in)!=2) {
                cout << 0 << endl;
                return 0;
            }
        }
        cout << pow2mod((n-1)/2) << endl;
    }
    return 0;
}
