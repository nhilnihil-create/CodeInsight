#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};
signed main() {
    string S;
    cin >> S;
    int ans = INF;
    for(char i = 'a'; i <= 'z'; i++) {
        bool flag = false;
        for(int j = 0; j < S.size(); j++) {
            if(S[j] == i) {
                flag = true;
            }
        }
        if(flag) {
            int cnt = 0;
            string T = S;
            while(true) {
                bool ok = false;
                string R = T;
                for(int k = 0; k < R.size(); k++) {
                    if(R[k] != i) {
                        ok = true;
                    }
                }
                if(ok == false) {
                    break;
                }
                cnt++;
                for(int k = 0; k < (int)T.size()-1; k++) {
                    if(T[k] == i || T[k+1] == i) {
                        R[k] = i;
                    }
                    else {
                        R[k] = 'Z';
                    }
                }
                T = R.substr(0,R.size()-1);
            }
            ans = min(ans,cnt);
        }
    }
    cout << ans << endl;
}
