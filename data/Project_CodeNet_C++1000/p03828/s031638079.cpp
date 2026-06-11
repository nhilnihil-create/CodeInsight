#include <bits/stdc++.h>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
typedef long long ll;
typedef long double ld;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll cnt[1001]={0};

// 素因数分解する
void div_prime(ll n){
    // 割る数の初期値
    ll a = 2;

    // √n>=aの間ループ
    while(n >= a * a){
        if(n % a == 0){
            cnt[a]++;
            n /= a;
        }
        else{
            a++;
        }
    }

    // 最後に残ったnは素因数
    cnt[n]++;
}

int main(void)
{
    ll N, i, ans=1;

    cin >> N;

    if(N==1) cout << 1 << endl;

    else{
        for(i=2; i<=N; i++){
            div_prime(i);
        }

        for(i=1; i<=N; i++){
            ans *= (cnt[i]+1);
            ans %= div1;
        }

        cout << ans << endl;
    }

    return 0;
}