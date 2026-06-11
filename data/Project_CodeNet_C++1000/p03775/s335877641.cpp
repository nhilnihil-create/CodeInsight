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

llint keta(llint n) {
    llint ans = 0;

    while(n>0) {
        n /= 10;
        ans++;
    }
    return ans;
}

int main(void) {
    llint n;
    cin >> n;

    llint a, b;
    for(llint in=1;in<sqrt(n)+1;in++) {
        if(n%in==0) a = in;
    }
    b = n / a;
    if(a<b) swap(a, b);
    
    cout << keta(a) << endl;
    return 0;
}
