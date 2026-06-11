#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int k, s;
    cin >> k >> s;
    int ans = 0;
    for(int x = 0; x <= k; x++) {
        for(int y = 0; y <= k; y++) {
            int z = s - x - y;
            if(z >= 0 && z <= k) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}