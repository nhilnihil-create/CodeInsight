#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;

    ll ans=0, tmp=0;
    rep(i,0,N){
        if      (S[i] == 'I') tmp++;
        else if (S[i] == 'D') tmp--;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}