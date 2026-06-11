//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;


int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;

    int num = s.size();
    rep(i, num) {
        int rr = 'z'-s[i]+1;
        rr %= 26;
        if(k >= rr) {
            s[i] = 'a';
            k -= rr;
        }
    }

    k %= 26;

    s[num-1] += k;

    cout << s << endl;
}