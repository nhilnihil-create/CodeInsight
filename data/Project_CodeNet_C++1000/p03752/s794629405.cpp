#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int n, k;
int main() {
    cin >> n >> k;
    vector<long long> a(n, 0);
    for(int i = 0; i < n; ++i) cin >> a.at(i);

    vector<long long> aup;
    long long start = a.at(0)+1;
    for(int i = 1; i < n; ++i) aup.push_back(a.at(i));
    int uplen = aup.size();
    k--;

    long long mincost = 1e18;
    for(int bit = 0; bit < (1<<uplen); ++bit) {
        vector<int> ss(uplen, 0);
        int cnt = 0;
        for(int i = 0; i < uplen; ++i) {
            if(bit & (1<<i)) {
                ss.at(i) = 1;
                cnt++;
            }
        }

        if(cnt == k) {
            long long cstart = start;
            long long sum = 0;
            for(int j = 0; j < uplen; ++j) {
                if(ss.at(j) == 1) {
                    if(cstart < aup.at(j)) {
                        cstart = aup.at(j)+1;
                    }else {
                        sum += (cstart - aup.at(j));
                        cstart++;
                    }
                }else {
                    if(cstart < aup.at(j)) {
                        cstart = aup.at(j)+1;
                    }
                }
            }
            chmin(mincost, sum);
        }
    }
    cout << mincost << endl;
}