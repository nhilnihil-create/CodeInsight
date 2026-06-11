#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    string s; cin >> s;
    int K; cin >> K;
    int n = s.size();

    int cnt = 0;
    rep(i, n){
        int x = s[i] - 'a';
        if(x == 0)continue;
        x = 26 - x;
        if(cnt + x > K)continue;
        cnt += x;
        s[i] = 'a';
    }

    if(cnt < K){
        int y = (K - cnt) % 26;
        int k = s[n-1] - 'a';
        k += y;
        k %= 26;
        s[n-1] = 'a' + k;
    }

    cout << s << endl;

    return 0;
}