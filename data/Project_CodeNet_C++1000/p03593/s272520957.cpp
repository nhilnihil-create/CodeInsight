#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(int)(a); (i)<(int)(b); ++(i))
#define rFor(i, a, b) for(int (i)=(int)(a)-1; (i)>=(int)(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}
template<class T> T div_floor(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>=0 ? a/b : (a+1)/b-1;
}
template<class T> T div_ceil(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>0 ? (a-1)/b+1 : a/b;
}

constexpr lint mod = 1e9+7;
constexpr lint INF = mod * mod;
constexpr int MAX = 100010;

int main(){
    int h, w, hp, wp;
    scanf("%d%d", &h, &w);
    hp = h%2, wp = w%2;
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    rep(i, h)rep(j, w){
        char c;
        scanf(" %c", &c);
        ++cnt[c-'a'];
    }

    rep(i, (h/2)*(w/2)){
        bool flag = false;
        rep(j, 26)if(cnt[j] >= 4){
            cnt[j] -= 4;
            flag = true;
            break;
        }
        if(!flag){
            puts("No");
            return 0;
        }
    }

    rep(i, hp * (w/2) + wp * (h/2)){
        bool flag = false;
        rep(j, 26)if(cnt[j] >= 2){
                cnt[j] -= 2;
                flag = true;
                break;
            }
        if(!flag){
            puts("No");
            return 0;
        }
    }

    rep(i, hp * wp){
        bool flag = false;
        rep(j, 26)if(cnt[j] >= 1){
                cnt[j] -= 1;
                flag = true;
                break;
            }
        if(!flag){
            puts("No");
            return 0;
        }
    }

    rep(j, 26)if(cnt[j]){
        puts("No");
        return 0;
    }
    puts("Yes");
}