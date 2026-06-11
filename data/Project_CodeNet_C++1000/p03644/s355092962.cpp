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
    int n;
    cin >> n;
    int acou = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        int cou = 0;
        bool t = true;
        int x = i;
        while(t) {
            if(x%2 == 0) {
                cou++;
                x /= 2;
            }
            else {
                t = false;
                break;
            }
        }
        if(acou <= cou) {
            acou = cou;
            ans = i;
        }
    }
    cout << ans << endl;

    return 0;
}