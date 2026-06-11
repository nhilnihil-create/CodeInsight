#include <bits/stdc++.h>
using namespace std;
#define rep(i, N)  for (int i = 0; i < (N); i++)

int main(){

    int N;
    cin >> N;
    string s, t;
    cin >> s >> t;

    int ans = 2*N;
    rep (i, N){
        if (s.substr(i, N-i) == t.substr(0, N-i)){
            ans -= N-i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}