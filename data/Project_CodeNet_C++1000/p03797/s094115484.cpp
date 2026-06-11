#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    ll n,m;
    cin >> n >> m;
    ll cnt = 0;
    ll c = n;

    if(2*n>m){
        cout << m/2 << endl;
        return 0;
    }

    cnt += n;
    m -= 2*n;
    cnt += m/4;
    cout << cnt << endl;
    return 0;
}