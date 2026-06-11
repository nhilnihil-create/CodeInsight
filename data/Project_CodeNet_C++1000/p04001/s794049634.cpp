#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    string S;
    cin >> S;
    int N = S.size();
    // 2^(N-1):文字列の隙間に"+"を入れる組み合わせ
    // N-1: 隙間の入れ方
    //cout << S[0] << endl;
    //cout << S[1] << endl;
    ll ans=0;
    for(int bit=0; bit < (1<<N-1); ++bit){
        ll temp=0;
        rep(i,N-1){
            temp *= 10;
            temp += S[i] - '0';
            
            if(bit & (1<<i)){
                ans += temp;
                temp = 0;
            }
        }
        //最終桁を足し合わせる
        temp *= 10;
        temp += S.back() - '0';
        ans += temp;
    }
    cout << ans << endl;
    return 0;
}