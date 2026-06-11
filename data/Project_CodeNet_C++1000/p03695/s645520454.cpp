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
    int n;
    cin >> n;

    vector<bool> col(8, false);
    int a, w=0;
    for(int in=0;in<n;in++) {
        cin >> a;
        // cout << a << endl;
        if(a<=399) col.at(0)=true;
        else if(a<=799) col.at(1)=true;
        else if(a<=1199) col.at(2)=true;
        else if(a<=1599) col.at(3)=true;
        else if(a<=1999) col.at(4)=true;
        else if(a<=2399) col.at(5)=true;
        else if(a<=2799) col.at(6)=true;
        else if(a<=3199) col.at(7)=true;
        else w++;
    }

    // for(auto c:col) cout << c << endl;

    int sum = 0;
    for(int in=0;in<8;in++) {
        if(col.at(in)==true) sum++;
    }

    if(w!=n) {
        cout << sum << " " << sum+w << endl;
    }
    else {
        cout << 1 << " " << w << endl;
    }
    
    return 0;
}
