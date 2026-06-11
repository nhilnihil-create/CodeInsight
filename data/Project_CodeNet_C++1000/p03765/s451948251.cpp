#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<int> cnt1(n+1, 0), cnt2(m+1, 0);
    rep(i, n){
        if(s[i] == 'A')cnt1[i+1] += 1 + cnt1[i];
        else cnt1[i+1] += 2 + cnt1[i];
    }
    rep(i, m){
        if(t[i] == 'A')cnt2[i+1] += 1 + cnt2[i];
        else cnt2[i+1] += 2 + cnt2[i];
    }

    int q;
    cin >> q;
    rep(i, q){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int sum1 = cnt1[b] - cnt1[a-1];
        int sum2 = cnt2[d] - cnt2[c-1];
        if(sum1 % 3 == sum2 % 3)cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}