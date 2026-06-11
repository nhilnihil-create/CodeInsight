#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n,A,B;
    cin >> n >> A >> B;
    string s;
    cin >> s;
    int cnt = 0;
    int bcnt = 0;
    rep(i,n){
        if(s[i] == 'a' && cnt < A+B){
            cout << "Yes" << endl;
            cnt++;
            continue;
        }
        if(s[i] == 'b' && cnt < A+B && bcnt < B){
            cout << "Yes" <<  endl;
            cnt++;
            bcnt++;
            continue;
        }
        cout << "No" << endl;
    }
    return 0;
}