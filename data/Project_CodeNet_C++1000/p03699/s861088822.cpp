#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1234567;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>s(N);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> s[i];
        sum+=s[i];
    }
    if(sum%10 != 0) {
        cout << sum << endl;
    }
    else {
        sort(s.begin(),s.end());
        for(int i = 0; i < s.size(); i++) {
            if(s[i]%10 != 0) {
                cout << sum-s[i] << endl;
                return 0;
            }
        }
        cout << 0 << endl;
    }
}
