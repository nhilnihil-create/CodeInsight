#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
int64_t INF = 1000000007;
// int64_t INF = 9223372036854775807;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    int64_t a,b,c;
    cin >> a >> b >> c;
    int64_t res = 0;
    if(a%2==0 || b%2==0 || c%2==0){
        res = 0;
    }else{
        if(b<c) swap(b,c);
        if(a<b) swap(a,b);
        res = b*c;
    }
    cout << res << endl;
}