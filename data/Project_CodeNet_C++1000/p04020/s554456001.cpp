#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) {
    return arg1.first > arg2.first;
}

int main(void) {
    ll n;
    cin >> n;

    ll a, sum=0, ans=0;
    for(int i=0;i<n+1;i++) {
        if(i==n) a=0;
        else cin >> a;
           
        if(a==0) {
            ans += sum/2;
            sum = 0;
        }
        else sum += a;
    }

    cout << ans << endl;
    return 0;
}
