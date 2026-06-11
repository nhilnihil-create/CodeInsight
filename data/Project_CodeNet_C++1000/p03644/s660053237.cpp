#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (int i = int(x); i < (int)(n); i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
using ll = long long;

int main() {
    ll n;
    cin >> n;

    int cnt = 0;
    int c = pow(2, cnt);
    int prevCnt = c;
    bool isFind = false;
    int res;

    while(isFind == false){
        cnt++;
        c = pow(2, cnt);
        if(n >= prevCnt && n < c){
            res = prevCnt;
            isFind = true;
        }
        prevCnt = c;
    }

    cout << res << endl;
}