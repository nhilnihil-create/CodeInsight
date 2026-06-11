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

    vi num(s.size());
    bool soo = true;
    rep(i, s.size()) {
        num[i] = s[i]-'a';
        if(num[i] != num[0]) {
            soo = false;
        }
    }


    int ans = 101;
    rep(i, 26) {
        vi num_;
        rep(j, s.size()) {
            num_.push_back(num[j]);
        }

        while(!num_.empty()) {
            bool check = true;
            rep(j, num_.size()-1) {
                if(num_[j] == i || num_[j+1] == i) {
                    num_[j] = i;
                } else {
                    num_[j] = 30;
                    check = false;
                }
            }
            num_.pop_back();
            int le = s.size()-num_.size();
            if(check) {
                ans = min(ans, le);
            }
        }
    }

    if(soo) {
        cout << 0 << endl;
    } else {
        cout << ans << endl;
    }
}