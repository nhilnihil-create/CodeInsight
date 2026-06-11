#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep1n(i,n) for(int i=1; i<=(n); ++i)
#define repxn(i,x,n) for(int i=x; i<=(n); ++i)
#define sort_u(x) sort((x).begin(),(x).end())
#define sort_d(x) sort((x).begin(),(x).end(), greater<int>())
#define pb push_back
#define INF 1001001001  // 浮動小数点型
#define INF_L 1001001001001001001  // 浮動小数点型
#define bit(n,m)(((n)>>(m))&1)  // nのmビット目が1
#define MOD 1000000007
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
#define yn2 {puts("YES");}else{puts("NO");}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}

ll digit_sum(ll n) {
    ll res = 0;
    while(n > 0) {
        // res += n%10; //桁和
        res++; //桁数
        n /= 10;
    }
    return res;
}

int main() {
    ll n; cin>>n;
    ll ans = INF_L;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            mins(ans, max(digit_sum(i), digit_sum(n/i)));
        }
    }
    cout<<ans<<endl;
}

/*
g++ c.cpp
./a.out
./problem.exe
oj d
oj t

debug:ctrl+shift+B problemin

*/
