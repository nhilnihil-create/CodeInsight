#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(void) {
    io;
    int k, s;
    cin >> k >> s;
    int answer = 0;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            int m = s - i - j;
            if (m>= 0  && m <=k && ((m+i+j) == s)) {
                answer++;
            }
        }
    }
    cout << answer << "\n";
    return 0;
}

