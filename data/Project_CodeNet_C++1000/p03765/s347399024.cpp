#include <bits/stdc++.h>
using namespace std;

int SA[100005];
int SB[100005];
int TA[100005];
int TB[100005];

int main(void){
    string s; cin >> s;
    string t; cin >> t;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A') SA[i+1] = 1;
        else SB[i+1] = 1;
        SA[i+1] += SA[i];
        SB[i+1] += SB[i];
    }
    for (int i = 0; i < t.length(); i++) {
        if (t[i] == 'A') TA[i+1] = 1;
        else TB[i+1] = 1;
        TA[i+1] += TA[i];
        TB[i+1] += TB[i];
    }
    
    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int SA_cnt = SA[b] - SA[a-1];
        int SB_cnt = SB[b] - SB[a-1];
        int TA_cnt = TA[d] - TA[c-1];
        int TB_cnt = TB[d] - TB[c-1];
        
        if (SA_cnt > TA_cnt) {
            SB_cnt += 2*(SA_cnt - TA_cnt);
            if (abs(SB_cnt - TB_cnt) % 3 == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else {
            TB_cnt += 2*(TA_cnt - SA_cnt);
            if (abs(SB_cnt - TB_cnt) % 3 == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    
}



