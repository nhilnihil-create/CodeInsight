#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    string S; cin >> S;
    int ss = S.size();
    int ans = 0;
    for (int i = 1; i < ss; i++){
        if(S[i] != S[i-1])ans++;
    }

    cout << ans << endl;

    return 0;
}