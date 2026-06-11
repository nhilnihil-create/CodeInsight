#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    cin >> n;
    vector<int> v(n, 0);

    vector<int> cnt(1e5 + 5, 0);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        cnt[v[i]]++;
    }

    
    ll ans = 1;
    if(n % 2 == 0) {
        int found = 0;
        int count = 0;
        for(int i = 0; i < cnt.size(); i++) {
            if(cnt[i] == 2) count++;

            if(cnt[i] != 2 && cnt[i] != 0) {
                found = 1;
            }
        }

        if(!found) {
            while(count--) {
                ans = (ans * 2) % ll(1e9 + 7);
            }
            ans = ans % ll(1e9 + 7);
        }
        else {
            ans = 0;
        }
    }
    else {
        int found = 0;
        int count_t = 0;
        int index_m = 0;
        int count_o = 0;

        for(int i = 0; i < cnt.size(); i++) {
            if(cnt[i] == 1) count_o++;
            else if(cnt[i] == 2) count_t++;
            else if(cnt[i] != 0)found = 1;
        }

        if(!found && count_o == 1 && cnt[0] == 1) {
            while(count_t--) {
                ans = (ans * 2) % ll(1e9 + 7);
            }
            ans = ans % ll(1e9 + 7);
        }
        else {
            ans = 0;
        }

    }

    cout << ans << endl;
    return 0;
}