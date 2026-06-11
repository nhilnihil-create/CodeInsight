#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int n;
    cin >> n;
    int cnt1 = 0;
    int cnt2 = 0;
    int ans1 = 0;
    int ans2 = 0;
    vector<int>a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt1+=a[i];
        cnt2+=a[i];
        if(i%2 == 0) {
            if(cnt1 <= 0) {
                ans1+=1-cnt1;
                cnt1 = 1;
            }
            if(cnt2 >= 0) {
                ans2+=cnt2+1;
                cnt2 = -1;
            }
        }
        if(i%2 == 1) {
            if(cnt1 >= 0) {
                ans1+=cnt1+1;
                cnt1 = -1;
            }
            if(cnt2 <= 0) {
                ans2+=1-cnt2;
                cnt2 = 1;
            }
        }
    }
    cout << min(ans1,ans2) << endl;
}