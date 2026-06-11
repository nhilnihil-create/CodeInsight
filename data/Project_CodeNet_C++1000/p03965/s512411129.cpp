#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string S;

int main() {
    cin >> S;
    int N = S.length();

    int g_cnt = 0;
    int p_cnt = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'p') {
            if (p_cnt < g_cnt) {
                p_cnt++;
            }
            else {
                g_cnt++;
                ans--;
            }
        }
        else {
            if (p_cnt < g_cnt) {
                p_cnt++;
                ans++;
            } 
            else {
                g_cnt++;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}
