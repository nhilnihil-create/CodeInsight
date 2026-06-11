#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    vector<string> hand(3);
    rep(i, 3) cin >> hand[i];

    int turn = 0;
    while(true){
        if(hand[turn].size() == 0)break;
        char card = hand[turn][0]; hand[turn].erase(0, 1);
        turn = card - 'a';
    }
    if(turn==0)cout << 'A' << ln;
    else if(turn==1)cout << 'B' << ln;
    else cout << 'C' << ln;
}