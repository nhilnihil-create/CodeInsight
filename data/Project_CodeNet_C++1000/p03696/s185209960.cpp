#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main() {
    int N;cin >> N;
    string S;cin >> S;
    int left = 0;
    int right = 0;
    int ct = 0;
    rep(i,N){
        if(S[i] == '('){
            if(ct < 0){
                left += (-1*ct);
                ct = 1;
            }
            else{
                ct++;
            }
        }
        if(S[i] == ')'){
            ct--;
        }
    }
    if(ct < 0)left += (-1*ct);
    else{
        right += ct;
    }

    rep(i,left)cout  << '(';
    cout << S ;
    rep(i,right)cout << ')' ;
    cout << endl;
}