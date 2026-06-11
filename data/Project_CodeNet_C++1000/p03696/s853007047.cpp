#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    int a = 0;
    int b = 0;
    int sa = 1001001001;
    rep(i, N){
        if(S[i] == '('){
            a++;
        } else {
            b++;
        }
        sa = min(sa, a-b);
    }

    sa *= -1;
    rep(i, sa){
        S = "(" + S;
    }

    if(sa > 0){
        a += sa;
    }
    int sa2 = a-b;
    rep(i, sa2){
        S = S + ")";
    }

    cout << S << endl;

    return 0;
}