#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(lint i=0, i##_len=(n); i<i##_len; ++i)

int main() {
    lint n,l; cin >> n >> l;
    lint a[100100];
    lint aSum = 0;
    rep(i,n) {
        cin >> a[i];
        aSum += a[i];
    }
    vector<int> ans;
    /*
    deque<lint> dq;
    rep(i,n) dq.push_back(a[i]);
    lint dqLeft = 1;
    lint dqRight = n-1;
    lint cnt = n-1;
    lint cc = aSum;
    vector<lint> ans;
    while (cc >= l && cnt > 0) {
        lint f,b;
        f = dq.front();
        b = dq.back();
        if (f < b) {
            cc -= f;
            ans.push_back(dqLeft);
            dqLeft ++;
            dq.pop_front();
        }
        else {
            cc -= b;
            ans.push_back(dqRight);
            dqRight --;
            dq.pop_back();
        }
        cnt --;
    }
    */
    rep(i,n-1) {
        if (a[i] + a[i+1] >= l) {
            for (int j=0; j<i; j++) {
                ans.push_back(j+1);
            }
            for (int j=n-2; j>i; j--) {
                ans.push_back(j+1);
            }
            ans.push_back(i+1);
            break;
        }
    }
    if (ans.size() == 0) cout << "Impossible" << endl;
    else {
        cout << "Possible" << endl;
        for (auto i: ans) cout << i << endl; 
    }
    
}