#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define FOR(i,a,b) for(int i=(a);i<(int)(b);i++)
#define rep(i,n) FOR(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define SZ(x) (int)(x).size()
#define ZERO(a) memset(a,0,sizeof(a))
#define dbg(x) cout<<#x<<": "<<(x)<<"\n"
#define pb push_back
#define eb emplace_back
#define mp make_pair

ll n;

int main() {
    cin >> n;
    ll i = 1;
    for(i=1; ; ++i){
        ll sum = (i * (i+1)) / 2;
        if(sum > n) break;
    }

    //dbg(sum[i]);
    for(int k=1; k<=i; ++k){
        if((i*(i+1))/2 - n == k) continue;
        cout << k << "\n";
    }

    return 0;
}
