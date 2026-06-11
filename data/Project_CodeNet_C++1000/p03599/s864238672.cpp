#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    map<int, bool> mp[2]; mp[0][0] = true; mp[1][0] = true;
    while(1) {
        int n = mp[0].size();
        for(auto it=mp[0].begin(); it!=mp[0].end(); it++) {
            if(it->first+100*A > F) continue;
            mp[0][it->first+100*A] = true;
            if(it->first+100*B > F) continue;
            mp[0][it->first+100*B] = true;
        }
        if(n == mp[0].size()) break;
    }
    while(1) {
        int n = mp[1].size();
        for(auto it=mp[1].begin(); it!=mp[1].end(); it++) {
            if(it->first+C > 30*E) continue;
            mp[1][it->first+C] = true;
            if(it->first+D > 30*E) continue;
            mp[1][it->first+D] = true;
        }
        if(n == mp[1].size()) break;
    }
    double mol = 0.0;
    int x=0, y=0;
    for(auto w=mp[0].begin(); w!=mp[0].end(); w++) {
        for(auto s=mp[1].begin(); s!=mp[1].end(); s++) {
            int ww = w->first;
            int ss = s->first;
            if(ww*E/100.0 >= ss&& ww+ss <= F) {
                if(mol <= (100.0*ss)/(double)(ww+ss)) {
                    mol = (100.0*ss)/(double)(ww+ss);
                    x = ww+ss; y = ss;
                }
            }
        }
    }
    printf("%d %d\n", x, y);
}